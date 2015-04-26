---
title: Problem 24. Lexicographic permutations
author: DHDave
date: 2015-01-24
layout: post
---

## 题目

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

$$ 012\ 021\ 102\ 120\ 201\ 210 $$
<!--more-->
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

[Problem 24. Lexicographic permutations](https://projecteuler.net/problem=24 "Problem 24")

## 翻译

排列是一个物体的有序安排。例如3124是1,2,3,4的一种排列。如果所有的排列按照数值或者字母序排序，我们称其为一个字典序。0,1,2的字典排列有：

$$ 012\ 021\ 102\ 120\ 201\ 210 $$

0, 1, 2, 3, 4, 5, 6, 7, 8, 9的第100万个字典排列是什么？

[题目24：0,1,2,3,4,5,6,7,8,9的第100万个字典排列是什么](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/25-240123456789100 "题目24")

## 题解

分析: $$ 1000000 = 2 \times 9! + 6 \times 8! + 6 \times 7! + 2 \times 6! + 5 \times 5! + 1 \times 4! + 2 \times 3! + 2 \times 2! $$

答案(answer): 2783915460

通过DFS算法验证，代码如下:

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

buf = [-1 for i in range(0, 11)]
flag = [False for i in range(0, 11)]
num = [-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

cnt = 0

def dfs(n):
    global cnt
    if(n == 11):
        cnt += 1
        if(cnt == 1000000):
            print(buf)
            return
    else:
        for i in range(1, 11):
            if not flag[i]:
                buf[n] = num[i]
                flag[i] = True
                dfs(n+1)
                flag[i] = False

if __name__ == '__main__':
    dfs(1)

# vim: set sw=4, ts=4
```
