---
title: Problem 42. Coded triangle numbers
author: DHDave
date: 2015-02-12
layout: post
---

## 题目

The n<sup>th</sup> term of the sequence of triangle numbers is given by, 

$$ tn = \frac{n(n+1)}{2} $$

so the first ten triangle numbers are:

$$ 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, \dots $$
<!--more-->
By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 

$$ 19 + 11 + 25 = 55 = t10 $$

If the word value is a triangle number then we shall call the word a triangle word.

Using [words.txt](../resource/p042_words.txt) (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

[Problem 42. Coded triangle numbers](https://projecteuler.net/problem=42 title="Problem 42")

## 翻译

三角形数序列中第 n 项的定义是：

$$ tn = \frac{n(n+1)}{2} $$ 

因此前十个三角形数是:

$$ 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, \dots $$

通过将一个单词中每个字母在字母表中的位置值加起来，我们可以将一个单词转换为一个数。例如，单词SKY的值为

$$ 19 + 11 + 25 = 55 = t10 $$

如果单词的值是一个三角形数，我们称这个单词为三角形单词。

[words.txt](../resource/p042_words.txt) (右键另存为)是一个16K的文本文件，包含将近两千个常用英语单词。在这个文件中，一共有多少个三角形词？

[题目42：这个英语词列表里共有多少个三角形词？](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/43-42 title="题目42")

## 题解

答案(answer): 162

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

import math

if __name__ == '__main__':
    s, cnt = None, 0
    with open("p042_words.txt", "r") as fp:
        s = fp.read().split(',')
    for t in s:
        v = 0
        for r in t[1:-1]:
            v += (ord(r)-ord('A')+1)
        k = int(math.sqrt(v*2))
        if (k*(k+1))//2 == v:
            cnt += 1
    print(cnt)

# vim: set sw=4, ts=4
```
