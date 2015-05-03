#! /usr/bin/env python
# -*- coding: utf-8

__author__ = 'He Tao'

'''
Leet Code OJ
004: Median of Two Sorted Arrays
    https://leetcode.com/problems/median-of-two-sorted-arrays/
'''

class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        
        def findKth(a, m, b, n, k):
            if m > n:
                return findKth(b, n, a, m, k)
            if m == 0:
                return b[k-1]
            if k == 1:
                return min(a[0], b[0])
            pa = min(k//2, m)
            pb = k - pa
            if a[pa-1] < b[pb-1]:
                return findKth(a[pa:], m-pa, b, n, k-pa)
            elif (a[pa-1] > b[pb-1]):
                return findKth(a, m, b[pb:], n-pb, k-pb)
            else:
                return a[pa - 1];

        m, n = len(nums1), len(nums2)
        a = findKth(nums1, m, nums2, n, (m+n)//2)
        b = findKth(nums1, m, nums2, n, (m+n)//2+1)
        if (m+n) % 2 == 0:
            return (a+b)/2.0
        else:
            return b
