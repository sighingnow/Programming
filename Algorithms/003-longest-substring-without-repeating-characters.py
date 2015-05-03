#! /usr/bin/env python
# -*- coding: utf-8

__author__ = 'He Tao'

'''
Leet Code OJ
002: Longest Substring Without Repeating Characters
'''

class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        last = [-1 for i in range(0, 256)]
        start = 0  # start position of current substring.
        ans = 0  # max length of substrings.
        for i in range(len(s)):
            ordval = ord(s[i])
            if last[ordval] >= start:  # update
                ans = max(i-start, ans)
                start = last[ordval] + 1
            last[ordval] = i
        return max(len(s)-start, ans)

# vim: set sw=4, ts=4, fileencoding=utf-8
