---
title: Problem 27. Quadratic primes
author: DHDave
date: 2015-01-27
layout: post
---

## 题目

Euler discovered the remarkable quadratic formula:

$$ n^2 + n + 41 $$

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

+ n<sup>2</sup> + an + b, where |a| < 1000 and |b| < 1000
+ where |n| is the modulus/absolute value of n. e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.

[Problem 27. Quadratic primes](https://projecteuler.net/problem=27 title="Problem 27")

## 翻译

欧拉曾发表过一个著名的二次公式：

$$ n^2 + n + 41 $$

这个公式对于0到39的连续数字能够产生40个质数。但是当 n = 40时，402 + 40 + 41 = 40(40 + 1) + 41能够被41整除。当n = 41时, 41² + 41 + 41显然也能被41整除。

利用计算机，人们发现了一个惊人的公式：n² − 79n + 1601。这个公式对于n = 0 到 79能够产生80个质数。这个公式的系数，−79 和1601的乘积是−126479。

考虑如下形式的二次公式：

+ n<sup>2</sup> + an + b, 其中|a| < 1000， |b| < 1000
+ 其中|n| 表示 n 的绝对值。例如， |11| = 11， |−4| = 4

对于能够为从0开始的连续的n产生最多数量的质数的二次公式，找出该公式的系数乘积。

[题目27：找出为连续数字产生最多质数的二次公式。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/28-27 title="题目27")

## 题解

分析: when n = 0, n<sup>2</sup> + an + b = b, so b must be a prime.

答案(answer): 

```python
#! /usr/bin/env python
# -*- coding: utf-8

if __name__ == '__main__':

# vim: set sw=4, ts=4
```
