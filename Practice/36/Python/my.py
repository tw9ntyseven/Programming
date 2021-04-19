from enum import Enum
from math import tan, cos, sin

import math
import copy

class CoordinateSystem(Enum):
    Cartesian = 1
    Polar = 2

class Point:
    def __init__(self, a1=0, a2=0, coord_system=CoordinateSystem.Cartesian):
        # a1 = '(-1.0,4.0)'
        if type(a1) == str:
            tmp_str = a1
            tmp_pos = a1.find(",")
            a1 = tmp_str[1:tmp_pos - 1]
            a2 = tmp_str[tmp_pos + 1:len(tmp_str) - 2]

        if coord_system == 1:
            self.x = a1
            self.y = a2
            self.r = (a1 * a1 + a2 * a2) ** (1/2)
            self.phi = 1 / tan(a2 / a2)
        else:
            self.r = a1
            self.phi = a2
            self.x = self.r * cos(self.phi)
            self.y = self.r * sin(self.phi)

    def get_x(self):
        return self.x

    def get_y(self):
        return self.y

    def get_r(self):
        return self.r

    def get_phi(self):
        return self.phi

    def set_x(self, x):
        self.x = x

    def set_y(self, y):
        self.y = y

    def set_r(self, r):
        self.r = r

    def set_phi(self, phi):
        self.phi = phi

    def __eq__(self, rhs):
        return self.x == rhs.x and self.y == rhs.y

    def __ne__(self, rhs):
        return not (self == rhs)

    def __repr__(self):
        return f'({self.x, self.y})'

    def __str__(self):
        return f'({self.x, self.y})'


p = Point('(-1.0,4.0)')

with open('data.txt') as fin:
    original = [Point(p) for p in fin.readline().split(', ')]

simulacrum = copy.deepcopy(original)
for p in simulacrum:
    print(p, end='')
    p.set_x(p.get_x() + 10)
    p.set_phi(p.get_phi() + 180 * math.pi / 180)
    p.set_y(-p.get_y())
    p.set_x(-p.get_x() - 10)
    print(p)

print('\nIt works!\n' if simulacrum == original else '\nIt not works!\n')