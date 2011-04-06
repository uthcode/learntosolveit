# module 'block' imported by twoview demo.

from gl import n3f, bgnpolygon, varray, endpolygon, lmbind
from GL import MATERIAL

# Draw a single 2x2x2 block with its center at (0, 0, 0)
# Arguments are the material indices (0 = don't call lmbind)
#
def block(m_front, m_back, m_left, m_right, m_top, m_bottom):
       #
       # Distances defining the sides
       #
       x_left = -1.0
       x_right = 1.0
       y_top = 1.0
       y_bottom = -1.0
       z_front = 1.0
       z_back = -1.0
       #
       # Top surface points: A, B, C, D
       #
       A = x_right, y_top, z_front
       B = x_right, y_top, z_back
       C = x_left, y_top, z_back
       D = x_left, y_top, z_front
       #
       # Bottom surface points: E, F, G, H
       #
       E = x_right, y_bottom, z_front
       F = x_right, y_bottom, z_back
       G = x_left, y_bottom, z_back
       H = x_left, y_bottom, z_front
       #
       # Draw front face
       #
       if m_front: lmbind(MATERIAL, m_front)
       n3f(0.0, 0.0, 1.0)
       face(H, E, A, D)
       #
       # Draw back face
       #
       if m_back: lmbind(MATERIAL, m_back)
       n3f(0.0, 0.0, -1.0)
       face(G, F, B, C)
       #
       # Draw left face
       #
       if m_left: lmbind(MATERIAL, m_left)
       n3f(-1.0, 0.0, 0.0)
       face(G, H, D, C)
       #
       # Draw right face
       #
       if m_right: lmbind(MATERIAL, m_right)
       n3f(1.0, 0.0, 0.0)
       face(F, E, A, B)
       #
       # Draw top face
       #
       if m_top: lmbind(MATERIAL, m_top)
       n3f(0.0, 1.0, 0.0)
       face(A, B, C, D)
       #
       # Draw bottom face
       #
       if m_bottom: lmbind(MATERIAL, m_bottom)
       n3f(0.0, -1.0, 0.0)
       face(E, F, G, H)

def face(points):
       bgnpolygon()
       varray(points)
       endpolygon()
