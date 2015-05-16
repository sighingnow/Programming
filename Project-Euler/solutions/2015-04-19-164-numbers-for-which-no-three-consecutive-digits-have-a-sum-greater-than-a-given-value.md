---
title: Problem 164. Numbers for which no three consecutive digits have a sum greater than a given value
author: DHDave
date: 2015-02-20
layout: post
---

## 题目

How many 20 digit numbers n (without any leading zero) exist such that no three consecutive digits of n have a sum greater than 9?

[Problem 164. Eight Divisors](https://projecteuler.net/problem=164 "Problem 164")

## 翻译

请问，存在多少个位数为20（没有前导0）,并且任意三个相邻数位之和不超过9的数字？

<!--more-->

[题目164：任意三个相邻数字位之和不超过给定值的数‏字。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/167-164 "题目164")

## 题解 

答案(answer): 378158756814587

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

dp = [[[0 for k in range(0, 20)] for j in range(0, 10)] for i in range(0, 10)]

def solve(a, b, s):
    if s == 0:
        return 1
    if dp[a][b][s] == 0:
        for i in range(0, 9-(a+b)+1):
            dp[a][b][s] += solve(b, i, s-1)
    return dp[a][b][s]

if __name__ == '__main__':
    ans = 0
    for i in range(1, 10):
        ans += solve(0, i, 20-1)
    print(ans)

# vim: set sw=4, ts=4
```

```haskell
main = do
    print $ sum [dp !! a !! b | a <- [1..9], b <- [0..9-a]]

mat = [[10-a-b | b<-[0..9-a]] | a<-[0..9]]

dp = iterate digitsum mat !! 17

digitsum x = [[sum [x!!b!!c | c<-[0..9-a-b]] | b<-[0..9-a]] | a<-[0..9]]
```

