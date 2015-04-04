---
title: Problem 19. Counting Sundays
author: DHDave
date: 2015-01-19
layout: post
---

## 题目

You are given the following information, but you may prefer to do some research for yourself.

+ 1 Jan 1900 was a Monday.
+ Thirty days has September,
+ April, June and November.
+ All the rest have thirty-one,
+ Saving February alone,
+ Which has twenty-eight, rain or shine.
+ And on leap years, twenty-nine.
+ A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
<!--more-->
[Problem 19. Counting Sundays](https://projecteuler.net/problem=19 title="Problem 19")

## 翻译

以下是一些已知信息，但是或许你需要自己做一些其他的调查。

+ 1900年1月1日是星期一。
+ 30天的月份有：9月，4月，6月，11月。
+ 此外的月份都是31天，当然2月除外。
+ 2月在闰年有29天，其他时候有28天。

    年份可以被4整除的时候是闰年，但是不能被400整除的世纪年（100的整数倍年）除外。

20世纪（1901年1月1日到2000年12月31日）一共有多少个星期日落在了当月的第一天？

[题目19: 20世纪有多少个星期日是当月的第一天](http://pe.spiritzhang.com/index.php/2011-05-11-09-44-54/20-1920 title="题目19")

## 题解(Python)

分析：使用蔡勒(Zeller)公式。

公式内容:

$$ w = (y+\lfloor{y/4}\rfloor+\lfloor{c/4}\rfloor-2c+\lfloor{26(m+1)/10}\rfloor+d-1)\ mod\ 7 $$

参数含义解释：

+ y: 年份的后两位数；
+ c: 年份的后两位数；
+ m: 月份；**注意**：月份的值在3-14之间，1月和2月应当作为上一年的13、14月来考虑。
+ d: 日。

答案(answer): 171

```python
#! /usr/bin/env python
# -*- coding: utf-8 -*-

def getWeek(year, mouth, day):
    ''' Zeller Method.
    '''
    if mouth < 3:
        year -= 1
        mouth += 12
    y, c = int(str(year)[2:4]), int(str(year)[0:2])
    week = (y + y//4 + c//4 - 2*c + 26*(mouth+1)//10 + day - 1) % 7
    return week

if __name__ == '__main__':
    cnt = 0
    for year in range(1901, 2000):
        for mouth in range(3, 15):
            if getWeek(year, mouth, 1) == 1:
                cnt += 1
    print(cnt)

# vim: set sw=4, ts=4
```
