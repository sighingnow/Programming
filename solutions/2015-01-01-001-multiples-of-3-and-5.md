---
title: Problem 1. Multiples of 3 and 5
author: DHDave
date: 2015-01-01
layout: post
---

Problem 1. Multiples of 3 and 5
-------------------------------

## 题目
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

[Problem 1. Multiples of 3 and 5](https://projecteuler.net/index.php?section=problems&id=1 title="Problem 1")

## 翻译
10以下的自然数中，属于3和5的倍数的有3,5,6和9，它们之和是23.

找出1000以下的自然数中，属于3和5的倍数的数字之和。

[题目1: 找出1000以下自然数中3和5的倍数之和。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/2-1100035 title="题目1")

## 题解

```python
ans = sum([i if(i%3==0 or i%5==0) else 0 for i in range(0, 1000)])
```
