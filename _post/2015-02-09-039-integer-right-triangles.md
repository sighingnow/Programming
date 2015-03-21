---
title: Problem 39. Integer right triangles
author: DHDave
date: 2015-02-09
layout: post
---

Problem 39. Integer right triangles
-----------------------------------

## 题目

If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

[Problem 39. Integer right triangles](https://projecteuler.net/problem=39 title="Problem 39")

## 翻译

如果p是一个直角三角形的周长，三角形的三边长{a,b,c}都是整数。对于p = 120一共有三组解：

{20,48,52}, {24,45,51}, {30,40,50}

对于1000以下的p中，哪一个能够产生最多的解？

[题目39：如果p是直角三角形{a,b,c}的周长，1000以下的p中哪一个具有最多的解？](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/40-39pabc1000p title="题目39")

## 题解

答案(answer): 840

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

if __name__ == '__main__':
    ans, maxcnt = 0, 0
    for s in range(3, 1000):
        cnt = 0
        for a in range(0, s//2):
            for b in range(1, (s-a)//2):
                if a*a == b*b + (s-a-b)*(s-a-b):
                    cnt += 1
        if cnt > maxcnt:
            maxcnt = cnt
            ans = s
    print(ans, maxcnt)

# vim: set sw=4, ts=4
```
