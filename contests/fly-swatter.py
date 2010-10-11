import math
N = int(raw_input())
def vol_of_sphere(radius):
    return (4.0/3.0 * math.pi * pow(radius,3))

for i in range(N):
    ip = raw_input()
    fly_radius, Radius, thickness, cylinder_radius, gap = (float(x) for x in
            ip.split(' '))
    print fly_radius, Radius, thickness, cylinder_radius,gap
    vol_fly = vol_of_sphere(fly_radius)
