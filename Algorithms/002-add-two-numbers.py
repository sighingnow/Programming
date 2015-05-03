#! /usr/bin/env python
# -*- coding: utf-8

__author__ = 'He Tao'

'''
Leet Code OJ
002: Add Two Numbers
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        answer = ListNode(-1)
        head, carry = answer, 0
        s, t = l1, l2
        while s is not None or t is not None:
            k = 0 if s is None else s.val
            v = 0 if t is None else t.val
            head.next = ListNode((k+v+carry)%10)
            head = head.next
            s = None if s is None else s.next
            t = None if t is None else t.next
            carry = (k+v+carry)//10

        while carry > 0:
            head.next = ListNode(carry % 10)
            carry = carry//10
            head = head.next

        if answer.next is None:
            answer.next = ListNode(0)
        return answer.next

# vim: set sw=4, ts=4, fileencoding=utf-8

