#! /usr/bin/env python
# -*- coding: utf-8

__author__ = 'He Tao'

'''
Leet Code OJ
005: Longest Palindromic Substring
    https://leetcode.com/problems/longest-palindromic-substring/

Manacher algorithm
http://en.wikipedia.org/wiki/Longest_palindromic_substring
'''

class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        T = '#'.join('^{}$'.format(s))
        n, p, c, r = len(T), [0]*len(T), 0, 0
        for i in range(1, n-1):
            p[i] = (r>i) and min(r-i, p[2*c-i])
            while T[i+1+p[i]] == T[i-1-p[i]]:
                p[i] += 1
            if i+p[i] > r:
                c, r = i, i+p[i]
        maxlen, centerindex = max((n, i) for i, n in enumerate(p))
        return s[(centerindex  - maxlen)//2: (centerindex  + maxlen)//2]
