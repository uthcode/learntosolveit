import pygame
from pygame.locals import *
 
def sub_rect(r1, r2):
    """remove the area of r2 from r1"""
    if not r1.colliderect(r2):
        return [r1]
 
    clip = r2.clip(r1)
 
    #first we have to see if there is a complete rect to each side of the removing rect
    need_com_left = False
    need_com_right = False
    need_com_top = False
    need_com_bottom = False
 
    if clip.left > r1.left:
        need_com_left = True
    if clip.right < r1.right:
        need_com_right = True
    if clip.top > r1.top:
        need_com_top = True
    if clip.bottom < r1.bottom:
        need_com_bottom = True
 
    left = None
    right = None
    top = None
    bottom = None
 
    if need_com_left: #ok, we also need to check top and bottom here...
        t = r1.top
        b = r1.bottom - r1.top
        l = r1.left
        r = clip.left - r1.left
        if need_com_top: #we need to cut a bit off the top of this
            t = clip.top
        if need_com_bottom:
            b = clip.bottom - t
 
        left = pygame.Rect(l, t, r, b)
    if need_com_right:
        t = r1.top
        b = r1.bottom - r1.top
        l = clip.right
        r = r1.right - clip.right
        if need_com_top:
            t = clip.top
        if need_com_bottom:
            b = clip.bottom - t
 
        right = pygame.Rect(l, t, r, b)
    if need_com_top:
        top = pygame.Rect(r1.left, r1.top, r1.width, clip.top-r1.top)
    if need_com_bottom:
        bottom = pygame.Rect(r1.left, clip.bottom, r1.width, r1.bottom-clip.bottom)
 
    ret = []
    for i in [left, right, top, bottom]:
        if i: ret.append(i)
 
    return ret
 
def sub_rect_list(r1, rl):
    dirty = [r1]
    for i in rl:
        new = []
        for x in dirty:
            new.extend(sub_rect(x, i))
        dirty = new
    return dirty
 
#test this!
a = pygame.Rect(0,0,100,100)
b = pygame.Rect(10,10,80,80)
c = pygame.Rect(80,80,20,20)
 
while True:
    dirty = sub_rect_list(a, [b, c])
     
    pygame.init()
    screen = pygame.display.set_mode((640, 480))
     
    back = pygame.Surface(a.size)
    back.fill((0,255,0))
     
    screen.blit(back, (0,0))
     
    new = pygame.Surface(a.size)
    new.fill((255,0,0))
     
    for i in dirty:
        if i:
            screen.blit(new, i.topleft, i)
            pygame.display.flip()
