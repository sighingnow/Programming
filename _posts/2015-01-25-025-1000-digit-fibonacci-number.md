---
title: Problem 25. 1000-digit Fibonacci number
author: DHDave
date: 2015-01-25
layout: post
---

## 题目

The Fibonacci sequence is defined by the recurrence relation:

$$ Fn = Fn−1 + Fn−2,\ where\ F1 = 1\ and\ F2 = 1. $$

Hence the first 12 terms will be:

<pre>
    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144
</pre>

The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?

[Problem 25. 1000-digit Fibonacci number](https://projecteuler.net/problem=25 title="Problem 25")

## 翻译

以下是斐波那契数列的递归定义：

$$ Fn = Fn−1 + Fn−2, F1 = 1, F2 = 1. $$

那么其12项为:

<pre>
    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144
</pre>

因此第12项，F12，是第一个包含三位数字的项。

斐波那契数列中第一个包含1000位数字的项是第几项？

[题目25：第一个包含1000位数字的斐波那契数列项是第几项](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/26-251000 title="题目25")

## 题解

答案(answer): 4782

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

if __name__ == '__main__':
    a, b, cnt = 1, 1, 1
    while str(a).__len__() < 1000:
        a, b = b, a+b
        cnt += 1
    print(cnt)

# vim: set sw=4, ts=4
```
