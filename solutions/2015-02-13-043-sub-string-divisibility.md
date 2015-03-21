---
title: Problem 43. Sub-string divisibility
author: DHDave
date: 2015-02-13
layout: post
---

Problem 43. Sub-string divisibility
------------------------------------

## 题目

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let <i>d</i><sub>1</sub> be the 1st digit, <i>d</i><sub>2</sub> be the 2nd digit, and so on. In this way, we note the following:

<ul>
<li><i>d</i><sub>2</sub><i>d</i><sub>3</sub><i>d</i><sub>4</sub>=406 is divisible by 2</li>
<li><i>d</i><sub>3</sub><i>d</i><sub>4</sub><i>d</i><sub>5</sub>=063 is divisible by 3</li>
<li><i>d</i><sub>4</sub><i>d</i><sub>5</sub><i>d</i><sub>6</sub>=635 is divisible by 5</li>
<li><i>d</i><sub>5</sub><i>d</i><sub>6</sub><i>d</i><sub>7</sub>=357 is divisible by 7</li>
<li><i>d</i><sub>6</sub><i>d</i><sub>7</sub><i>d</i><sub>8</sub>=572 is divisible by 11</li>
<li><i>d</i><sub>7</sub><i>d</i><sub>8</sub><i>d</i><sub>9</sub>=728 is divisible by 13</li>
<li><i>d</i><sub>8</sub><i>d</i><sub>9</sub><i>d</i><sub>10</sub>=289 is divisible by 17</li>
</ul>

Find the sum of all 0 to 9 pandigital numbers with this property.

[Problem 43. Sub-string divisibility](https://projecteuler.net/problem=43 title="Problem 43")

## 翻译

1406357289是一个pandigital数，因为它包含了0到9之间每个数字且只包含了一次。此外它还有一个有趣的子串整除性质。

令<i>d</i><sub>1</sub>表示其第一位数字，<i>d</i><sub>2</sub>表示第二位，以此类推。这样我们可以得到：

<ul>
<li><i>d</i><sub>2</sub><i>d</i><sub>3</sub><i>d</i><sub>4</sub>=406 is divisible by 2</li>
<li><i>d</i><sub>3</sub><i>d</i><sub>4</sub><i>d</i><sub>5</sub>=063 is divisible by 3</li>
<li><i>d</i><sub>4</sub><i>d</i><sub>5</sub><i>d</i><sub>6</sub>=635 is divisible by 5</li>
<li><i>d</i><sub>5</sub><i>d</i><sub>6</sub><i>d</i><sub>7</sub>=357 is divisible by 7</li>
<li><i>d</i><sub>6</sub><i>d</i><sub>7</sub><i>d</i><sub>8</sub>=572 is divisible by 11</li>
<li><i>d</i><sub>7</sub><i>d</i><sub>8</sub><i>d</i><sub>9</sub>=728 is divisible by 13</li>
<li><i>d</i><sub>8</sub><i>d</i><sub>9</sub><i>d</i><sub>10</sub>=289 is divisible by 17</li>
</ul>

求所有具有如上性质的0到9pandigital数的和。

[题目43：找出所有具有异常子串整除性的pandigital数之和。](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/44-43pandigital title="题目43")

## 题解

答案(answer): 16695334890

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

from itertools import permutations

def to_int(t):
    ans = 0
    for e in t:
        ans = ans * 10 + int(e)
    return ans

def judge(t):
    prime = [0, 2, 3, 5, 7, 11, 13, 17]
    for i in range(1, 8):
        if to_int(t[i:i+3]) % prime[i] != 0:
            return False
    return True
    
if __name__ == '__main__':
    ans = 0
    for item in permutations("0123456789"):
        if item[0] != '0' and judge(item):
            print(item)
            ans += to_int(item)
    print(ans)
    
# vim: set sw=4, ts=4
```
