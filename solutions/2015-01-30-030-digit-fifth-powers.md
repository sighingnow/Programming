---
title: Problem 30. Digit fifth powers
author: DHDave
date: 2015-01-30
layout: post
---

Problem 30. Digit fifth powers
-------------------------------

## 题目

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

$$ 1634 = 1^4 + 6^4 + 3^4 + 4^4 $$
$$ 8208 = 8^4 + 2^4 + 0^4 + 8^4 $$
$$ 9474 = 9^4 + 4^4 + 7^4 + 4^4 $$

As 1 = 1<sup>4</sup> is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

[Problem 30. Digit fifth powers](https://projecteuler.net/problem=30 title="Problem 30")

## 翻译

令人惊奇的，只有三个数能够写成它们各位数的四次方之和：

$$ 1634 = 1^4 + 6^4 + 3^4 + 4^4 $$
$$ 8208 = 8^4 + 2^4 + 0^4 + 8^4 $$
$$ 9474 = 9^4 + 4^4 + 7^4 + 4^4 $$

1 = 1<sup>4</sup>没有被算作在内因为它不是一个和。

这些数字的和是 1634 + 8208 + 9474 = 19316.

找出所有能被写成各位数字五次方之和的数之和。

[题目30：找出所有能够写成各位数字5次方之和的数之和](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/31-305 title="题目30")

## 题解

分析：7 * 9<sup>5</sup> = 413343, 因此，最多为一个六位数

答案(answer): 443839

```python
#! /usr/bin/env python
# -*- coding: utf-8

if __name__ == '__main__':
    ans = 0
    for i in range(2, 1000000):
        if i == sum([int(j)**5 for j in str(i)]):
            ans += i
    print(ans)

# vim: set sw=4, ts=4
```
