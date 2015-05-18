PyBrainFuck
============

A simple [BrainFuck][1] interperter wirtten in Python.

Intro
-----

Brainfuck is an esoteric programming language noted for its extreme minimalism. The language consists of only eight simple commands and an instruction pointer. Nevertheless, it was shown to be Turing-complete.

The eight language commands, each consisting of a single character:

| Character | Meaning                                                               |
|:---------:|-----------------------------------------------------------------------|
| `>`       | increment the data pointer (to point to the next cell to the right).  |
| `<`       | decrement the data pointer (to point to the next cell to the left).   |
| `+`       | increment (increase by one) the byte at the data pointer.             |
| `-`       | decrement (decrease by one) the byte at the data pointer.             |
| `.`       | output the byte at the data pointer.                                  |
| `,`       | accept one byte of input, storing its value in the byte at the data pointer. |
| `[`       | if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching `]` command. |
| `]`       | if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching `[` command. |

In Chinese:


| 字符 | 含义                                                              |
|:----:|-------------------------------------------------------------------|
| `>`  | 指针加一                                                          |
| `<`  | 指针减一                                                          |
| `+`  | 指针指向的字节的值加一                                            |
| `-`  | 指针指向的字节的值减一                                            |
| `.`  | 输出指针指向的单元内容（ASCII码）                                 |
| `,`  | 输入内容到指针指向的单元（ASCII码）                               |
| `[`  | 如果指针指向的单元值为零，向后跳转到对应的]指令的次一指令处       |
| `]`  | 如果指针指向的单元值不为零，向前跳转到对应的[指令的次一指令处     |

Brainfuck programs can be translated into C using the following substitutions, assuming ptr is of type unsigned char* and has been initialized to point to an array of zeroed bytes:

| brainfuck command | C equivalent                                              |
|:-----------------:|-----------------------------------------------------------|
| (Program Start)   | char array[infinitely large size] = {0}; char *ptr=array; |
| >                 | ++ptr;                                                    |
| <                 | --ptr;                                                    |
| +                 | ++*ptr;                                                   |
| -                 | --*ptr;                                                   |
| .                 | putchar(*ptr);                                            |
| ,                 | *ptr=getchar();                                           |
| [                 | while (*ptr) {                                            |
| ]                 | }                                                         |

Usage
-----

You need Python 3 installed on your computer.

Just run:

    python PyBrainFuck.py xxx.bf

and you will see the result of xxx.bf.

Example
-------

Input:

    ++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.

Output:

    Hello World!

Test
-----

Some test cases come from [rosettacode.org][2] and [Wikipedia -- Brainfuck][3].

License
--------

The MIT License (MIT)

Copyright (c) 2015 He Tao


<!---------------------------links------------------------>

[1]: http://en.wikipedia.org/wiki/Brainfuck
[2]: http://rosettacode.org/wiki/Category:Brainf***
[3]: http://zh.wikipedia.org/wiki/Brainfuck

