#!/usr/bin/env python
# -*- coding: utf-8 -*-

#ZOJ 1151

def reverse(string):
    return string[::-1]

def main():
    n = int(raw_input())
    for i in range(0, n):
        raw_input()
        m = int(raw_input())
        for s in range(0, m):
            string = raw_input()
            strL = string.split(" ")
            for j in range(0, strL.__len__() - 1):
                print reverse(strL[j]),
            print reverse(strL[strL.__len__() - 1])
        if i < n - 1:
            print ""
    return 0

if __name__ == '__main__':
    main()

