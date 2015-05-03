#! /usr/bin/env python
# -*- coding: utf-8

__author__ = 'He Tao'

'''
Leet Code OJ
001: Two Sums
'''

class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        comb, index = [], 0
        for n in num:
            index += 1
            comb.append((n, index))
        comb.sort(key = (lambda x : x[0]))
        first, last, ans = 1-1, index-1, comb[0][0]+comb[index-1][0]
        while ans != target:
            if ans < target:
                first += 1
            else:
                last -= 1
            ans = comb[first][0]+comb[last][0]
        if comb[first][1] < comb[last][1]:
            return comb[first][1], comb[last][1]
        else:
            return comb[last][1], comb[first][1]

