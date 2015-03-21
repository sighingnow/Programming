---
title: Problem 17. Number letter counts
author: DHDave
date: 2015-01-17
layout: post
---

Problem 17. Number letter counts
--------------------------------

## 题目
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

*NOTE*: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

[Problem 17. Number letter counts](https://projecteuler.net/problem=17 title="Problem 17")

## 翻译
如果用英文写出数字1到5: one, two, three, four, five, 那么一共需要3 + 3 + 5 + 4 + 4 = 19个字母。

如果数字1到1000（包含1000）用英文写出，那么一共需要多少个字母？

*注意*: 空格和连字符不算在内。例如，342 (three hundred and forty-two)包含23个字母； 115 (one hundred and fifteen)包含20个字母。"and" 的使用与英国标准一致。

[题目17:用英文写出1到1000的所有数字需要多少个字母](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/18-1711000 title="题目17")

## 题解(Python)

答案(answer): 21124

数字的规律

<pre>
0：null   10：ten        20：twenty          ......      100：one hundred
1：one    11：eleven     21：twenty-one      ......      101：one hundred and one
2：two    12：twelve     22：twenty-two      ......      102：one hundred and two
.........
1000 one thousand
</pre>

可以看出当十位是1时，要单独考虑。

当十位数不是1时，是在十位数的基础上加上各位数的长度

当有百位数时，百位由百位上的数加上hundred and

为整百时，会少一个and

```python
#! /usr/bin/env python
# -*- coding: utf-8

a = [0,3,3,5,4,4,3,5,5,4]
b = [0,0,6,6,5,5,5,7,6,6]
c = [3,6,6,8,8,7,7,9,8,8]

ans = 0

for i in range(1, 1000):
    if i//10%10 == 1: # 1 at units digit
        ans += c[i%10]
    else:
        ans += a[i%10]
        ans += b[i//10%10]
    if i // 100 > 0: # number greater than 99 (three digits)
        if i % 100 == 0:
            ans += (a[i//100]+7)
        else:
            ans += (a[i//100]+10)
ans += 11 # 1000
print(ans)

# vim: set sw=4, ts=4, fileencoding=utf-8
```

## 参考(Reference): 
1. [[Project Euler] Problem 17 - xiatwhu - 博客园](http://www.cnblogs.com/xianglan/archive/2011/03/03/1970334.html)
