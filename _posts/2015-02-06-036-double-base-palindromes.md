---
title: Problem 36. Double-base palindromes
author: DHDave
date: 2015-02-06
layout: post
---

## 题目

The decimal number, 585 = 1001001001<sub>2</sub>(binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
<!--more-->
[Problem 36. Double-base palindromes](https://projecteuler.net/problem=36 "Problem 36")

## 翻译

十进制数字585 = 1001001001<sub>2</sub> (二进制),

可以看出在十进制和二进制下都是回文（从左向右读和从右向左读都一样）。

求100万以下所有在十进制和二进制下都是回文的数字之和。

（注意在两种进制下的数字都不包括最前面的0）

[题目36：出100万以下所有十进制和二进制表示都是回文的数字之和。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/37-36100 "题目36")

## 题解

答案(answer): 872187

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

def judge(n):
    s = str(n)
    l = len(s)
    for i in range(0, l):
        if s[i] != s[l-1-i]:
            return False
    s = bin(n)[2:]
    l = len(s)
    for i in range(0, l):
        if s[i] != s[l-1-i]:
            return False
    return True

if __name__ == '__main__':
    ans = 0
    for i in range(1, 1000000, 2):
        if judge(i):
            ans += i
    print(ans)

# vim: set sw=4, ts=4
```
