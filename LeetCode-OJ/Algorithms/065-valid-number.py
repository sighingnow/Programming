#! /usr/bin/env python
# -*- coding: utf-8

__author__ = 'He Tao'

'''
Leet Code OJ
065: Valid Number
    https://leetcode.com/problems/valid-number/
'''

class Solution:
    # @param s, a string
    # @return a boolean
    def isNumber(self, s):
        try:
            float(s)
        except:
            return False
        else:
            return True
