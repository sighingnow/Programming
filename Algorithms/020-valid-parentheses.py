#! /usr/bin/env python
# -*- coding: utf-8

__author__ = 'He Tao'

'''
Leet Code OJ
020: Valid Parentheses
'''

class Solution:
    # @return a boolean
    def isValid(self, s):
        stack = []
        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            else:
                try:
                    t = stack.pop()
                except:
                    return False
                else:
                    if c == ')' and t != '(':
                        return False
                    if c == ']' and t != '[':
                        return False
                    if c == '}' and t != '{':
                        return False
        if stack.__len__() != 0:
            return False
        return True

# vim: set sw=4, ts=4, fileencoding=utf-8
