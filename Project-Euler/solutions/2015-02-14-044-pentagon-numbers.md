---
title: Problem 44. Pentagon numbers
author: DHDave
date: 2015-02-14
layout: post
---

## 题目

Pentagonal numbers are generated by the formula, P<sub>n</sub>=n(3n−1)/2. The first ten pentagonal numbers are:

$$ 1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ... $$

It can be seen that P<sub>4</sub> + P<sub>7</sub> = 22 + 70 = 92 = P<sub>8</sub>. However, their difference, 70 − 22 = 48, is not pentagonal.
<!--more-->
Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |P<sub>k</sub> − P<sub>j</sub>| is minimised; what is the value of D?

[Problem 44. Pentagon numbers](https://projecteuler.net/problem=44 "Problem 44")

## 翻译

五角数通过如下公式定义：P<sub>n</sub>=n(3n−1)/2。前十个五角数是：

$$ 1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ... $$

可以看出P<sub>4</sub> + P<sub>7</sub> = 22 + 70 = 92 = P<sub>8</sub>. 但是它们的差70 − 22 = 48却不是五角数。

找出最小的五角数对Pj 和 Pk,， 使得它们的和与差都是五角数，并且D = |P<sub>k</sub> − P<sub>j</sub>| 取到最小。这时D的值是多少?

[题目44：找出最小的和与差都是五角数的五角数对。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/45-44 "题目44")

## 题解

答案(answer): 5482660

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

number = [n*(3*n-1)//2 for n in range(0, 1000000)]
m = {}

if __name__ == '__main__':
    u = 1
    while u < 10000:
        v = u+1
        while v < 10000:
            if number[u]+number[v] in number and number[v]-number[u] in number:
                print(number[u], number[v], number[v]-number[u])
            v += 1
        u += 1

# vim: set sw=4, ts=4
```