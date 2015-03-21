---
title: Problem 26. Reciprocal cycles
author: DHDave
date: 2015-01-26
layout: post
---

Problem 26. Reciprocal cycles
-----------------------------

## 题目

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

<pre><code>
    1/2  = 	0.5
    1/3  = 	0.(3)
    1/4  = 	0.25
    1/5  = 	0.2
    1/6  = 	0.1(6)
    1/7  = 	0.(142857)
    1/8  = 	0.125
    1/9  = 	0.(1)
    1/10 = 	0.1
</code></pre>

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

[Problem 26. Reciprocal cycles](https://projecteuler.net/problem=26 title="Problem 26")

## 翻译
分子为1的分数称为单分数。分母是2到10的单分数用十进制表示如下：

<pre>
    1/2  = 	0.5
    1/3  = 	0.(3)
    1/4  = 	0.25
    1/5  = 	0.2
    1/6  = 	0.1(6)
    1/7  = 	0.(142857)
    1/8  = 	0.125
    1/9  = 	0.(1)
    1/10 = 	0.1
</pre>

其中0.1(6) 表示 0.166666...,因此它又一个长度为1的循环圈。可以看出1/7拥有一个6位的循环圈。

找出小于1000的数字d，1/d 的十进制表示含有最长的循环圈。

[题目26：找出小于1000的数字中令1/d拥有最长循环圈的数字d](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/27-2610001dd title="题目26")

## 题解

分析：模拟除法的笔算过程，当某个被除数值出现两次是，即找到最长循环节的长度。

答案(answer): 983

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

def div(n):
    cnt, start = 0, 1
    record = [-1 for i in range(0, 1001)]
    while True:
        while start < n:
            start *= 10
            cnt += 1
        start %= n
        if start == 0:
            return -1
        if record[start] != -1:
            break
        else:
            record[start] = cnt
    return cnt - record[start]

if __name__ == '__main__':
    index, cnt = -1, -1
    for i in range(1, 1001):
        if cnt < div(i):
            index, cnt = i, div(i)
    print(index, cnt)

# vim: set sw=4, ts=4
```