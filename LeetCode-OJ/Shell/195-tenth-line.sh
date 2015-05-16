#! /bin/bash

:<< '
Author: He Tao
Leet Code OJ
195: Tenth Line
    https://leetcode.com/problems/tenth-line/
'

# Read from the file file.txt and output the tenth line to stdout.
awk 'NR==10' file.txt

