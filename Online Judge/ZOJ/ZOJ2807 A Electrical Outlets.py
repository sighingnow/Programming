#!/usr/bin/env python
# -*- coding: utf-8 -*-

#ZOJ 2807

def main():
    n = int(raw_input())
    for i in range(0, n):
        strL = raw_input()
        L = strL.split(" ")
        t = 0
        for s in range(1, int(L[0]) + 1):
            p = int(L[s])
            t += p
        print t - int(L[0]) + 1
    return 0

if __name__ == '__main__':
    main()

