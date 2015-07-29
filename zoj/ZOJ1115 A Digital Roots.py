#!/usr/bin/env python
# -*- coding: utf-8 -*-

#ZOJ 1115

def main():
    while True:
        x = int(raw_input())
        if x == 0:
            break
        while x >= 10:
            n = 0
            while x / 10 >= 1:
                n = n + x % 10
                x /= 10
            n += x
            x = n
        print x
            
    return 0

if __name__ == '__main__':
    main()

