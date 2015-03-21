---
title: Problem 28. Number spiral diagonals
author: DHDave
date: 2015-01-28
layout: post
---

Problem 28. Number spiral diagonals
----------------------------------

## 题目

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

<center><pre>
21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
</pre></center>

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

[Problem 28. Number spiral diagonals](https://projecteuler.net/problem=28 title="Problem 28")

## 翻译

从数字1开始向右顺时针方向移动，可以得到如下的5×5的螺旋：

<center><pre>
21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
</pre></center>

可以算出对角线上数字之和是101.

1001×1001的螺旋中对角线上数字之和是多少？

[题目28：1001×1001的螺旋中两条对角线之和是多少](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/29-281001t1001 title="题目28")

## 题解

分析：递推式

$$ S_1 = 1 $$
$$ S_n = S_{n-1} + 16 n ^ 2 - 28 \times n + 16, \ (n > 1) $$

答案(answer): 5343342001

```python
#! /usr/bin/env python
# -*- coding: utf-8

if __name__ == '__main__':
    ans, i = 1, 1
    while i < 1001:
        i += 1
        ans = ans + (16 * i - 28) * i + 16
    print(i, ans)

# vim: set sw=4, ts=4
```
