---
title: Problem 18. Maximum path sum I
author: DHDave
date: 2015-01-18
layout: post
---

## 题目

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

<center><pre>
3
7 4
2 4 6
8 5 9 3
</pre></center>
<!--more-->
That is, $$3 + 7 + 4 + 9 = 23.$$

Find the maximum total from top to bottom of the triangle below:

<center><pre>
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
</pre></center>

*NOTE*: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

[Problem 18. Maximum path sum I](https://projecteuler.net/problem=18 title="Problem 18")

## 翻译

从下面的三角形的顶端开始，向下面一行的相邻数字移动，从顶端到底端的最大总和为23.

<center><pre>
3
7 4
2 4 6
8 5 9 3
</pre></center>

也就是 $$ 3 + 7 + 4 + 9 = 23.$$

找出从以下三角形的顶端走到底端的最大总和：

<center><pre>
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
</pre></center>

[题目18:找出从三角形顶端走到底端的最大和](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/19-18 title="题目18")

## 题解(Python)

分析：树形DP

状态转移方程:$$ dp[i] = max(dp[i-1][j-1], dp[i-1][j]) + number[i][j] $$

答案(answer): 1074

```python
#! /usr/bin/env python
# -*- coding: utf-8

num = [[0] for i in range(0, 16)]
raw = 1
dp = [[0 for i in range(0, 16)] for j in range(0, 16)]

with open("index.txt", "r") as fp:
    s = fp.read().split('\n')
    for t in s:
        t = t.split(' ')
        for i in range(0, t.__len__()):
            num[raw].append(int(t[i]))
        raw += 1

for i in range(1, 16):
    for j in range(1, i+1):
        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + num[i][j]

print(max(dp[15]))

# vim: set sw=4, ts=4, fileencoding=utf-8
```
