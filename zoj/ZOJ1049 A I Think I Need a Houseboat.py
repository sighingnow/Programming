# -*- coding: utf-8 -*-
#! /usr/bin/python

import math

def solve():
    t = int(raw_input())
    for i in range(1, t+1):
        x, y = raw_input().split(' ')
        x = float(x)
        y = float(y)
        s = (x ** 2 + y ** 2) * math.pi
        print 'Property %d: This property will begin eroding in year %d.' %(i, int(s/2/50)+1)
    print 'END OF OUTPUT.'

def main():
    solve()

if __name__ == '__main__':
    main()
