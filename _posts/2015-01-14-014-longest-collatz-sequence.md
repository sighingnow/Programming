---
title: Problem 14. Longest Collatz sequence
author: DHDave
date: 2015-01-14
layout: post
---

## 题目
The following iterative sequence is defined for the set of positive integers:

$$n → n/2 (n is even)$$
$$n → 3n + 1 (n is odd)$$
Using the rule above and starting with 13, we generate the following sequence:
$$13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1$$
<!--more-->
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

*NOTE*: Once the chain starts the terms are allowed to go above one million.

[Problem 14. Longest Collatz sequence](https://projecteuler.net/problem=14 title="Problem 14")

## 翻译
以下迭代序列定义在整数集合上：
$$n → n/2 (当n是偶数时)$$
$$n → 3n + 1 (当n是奇数时)$$
应用以上规则，并且以数字13开始，我们得到以下序列：
$$ 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1 $$
可以看出这个以13开始以1结束的序列包含10个项。虽然还没有被证明（Collatz问题），但是人们认为在这个规则下，以任何数字开始都会以1结束。

以哪个不超过100万的数字开始，能给得到最长的序列？

*注意*: 一旦序列开始之后，也就是从第二项开始，项是可以超过100万的。

[题目14:找出以100万以下的数字开始的最长序列](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/15-14100 title="题目14")

## 题解(Python)

答案(answer): 837799

```python
#! /usr/bin/env python
# -*- coding: utf-8

num = [0 for i in range(0, 1000001)]

def collatz(n):
    if n == 1:
        return 1
    ans = 0
    if n > 1000000:
        if n % 2 == 0:
            ans = collatz(n // 2) + 1
        else:
            ans = collatz(3 * n + 1) + 1
    else:
        if num[n] == 0:
            if n % 2 == 0:
                num[n] = collatz(n // 2) + 1
            else:
                num[n] = collatz(3 * n + 1) + 1
        ans = num[n]
    return ans

max_index = 0

for i in range(1, 1000001):
    if num[i] == 0:
        num[i] = collatz(i)
        if num[i] > num[max_index]:
            max_index = i

print(max_index)

# vim: set sw=4, ts=4, fileencoding=utf-8
```
