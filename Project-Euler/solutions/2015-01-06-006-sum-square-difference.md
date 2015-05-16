---
title: Problem 6. Sum square difference
author: DHDave
date: 2015-01-06
layout: post
---

## 题目
The sum of the squares of the first ten natural numbers is,
<center>$$
1^2 + 2^2 + ... + 10^2 = 385
$$</center>
The square of the sum of the first ten natural numbers is,
<center>$$
(1 + 2 + ... + 10)^2 = 55^2 = 3025
$$</center>
<!--more-->
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
<center>$$3025 − 385 = 2640.$$</center>

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

[Problem 6. Sum square difference](https://projecteuler.net/problem=6 "Problem 6")

## 翻译
前十个自然数的平方和是：
<center>$$
1^2 + 2^2 + ... + 10^2 = 385
$$</center>
前十个自然数的和的平方是：
<center>$$
(1 + 2 + ... + 10)^2 = 55^2 = 3025
$$</center>
所以平方和与和的平方的差是<center>$$3025 − 385 = 2640.$$</center>

找出前一百个自然数的平方和与和平方的差。

[题目6：找出最小的能被1-20中每个数整除的数](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/6-51-20 "题目6")

## 题解(Python)
```python
ans = sum([i for i in range(1, 101)])**2 - sum([i**2 for i in range(1, 101)])
```
