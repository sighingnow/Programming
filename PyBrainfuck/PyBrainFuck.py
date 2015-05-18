#! /usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'He Tao'

'''
PyBrainFuck: A simple BrainFuck interperter.

Reference: 
    http://en.wikipedia.org/wiki/Brainfuck

Date: 2015-05-18
'''

import sys

class BrainFuck:
    def __init__(self):
        self.data = [0]
        self.pc = 0  # program counter.
        self.dp = 0  # data address pointer
        self.inbuffer = ''
        self.code = ''
        self.ins = '<>+-.,[]'
        self.cmd = {
            '+': self.__increment, '-': self.__decrement,
            '>': self.__forward,   '<': self.__backward,
            '.': self.__output,    ',': self.__input,
            '[': self.__while_in,  ']': self.__while_out,
        }

    def __increment(self):
        self.data[self.dp] += 1
    def __decrement(self):
        self.data[self.dp] -= 1
    def __forward(self):
        if self.dp + 1 >= len(self.data):
            self.data.append(0)
        self.dp += 1
    def __backward(self):
        if self.dp - 1 < 0:
            raise Exception('can\'t move backward at %d'%(self.dp))
        self.dp -= 1

    def __output(self):
        print('%c'%(self.data[self.dp]), end = '')
    def __input(self):
        if len(self.inbuffer) == 0:
            self.inbuffer = input('getchar: ')
        self.data[self.dp] = ord(self.inbuffer[0])
        self.inbuffer = self.inbuffer[1:]

    def __while_in(self):
        '''while statement entry'''
        if self.data[self.dp] != 0:
            return
        npc, s = self.pc, 0 # npc: next pc, s: stack counter.
        while npc < len(self.code):
            if self.code[npc] == '[': s += 1
            if self.code[npc] == ']': s -= 1
            if s == 0: break
            npc += 1
        if s != 0:
            raise Exception('Syntax error: ] can\'t match with [')
        self.pc = npc
    def __while_out(self):
        '''while statement exit'''
        if self.data[self.dp] == 0:
            return
        npc, s = self.pc, 0 # npc: next pc, s: stack counter.
        while npc >= 0:
            if self.code[npc] == ']': s += 1
            if self.code[npc] == '[': s -= 1
            if s == 0: break
            npc -= 1
        if s != 0:
            raise Exception('Syntax error: [ can\'t match with ]')
        self.pc = npc

    def run(self, program):
        self.__init__()
        for c in program:
            if c in self.ins:
                self.code += c
            elif c.isspace():
                pass
            else:
                raise Exception('Syntax error: %c is not a valid character.'%(c))
        while self.pc != len(self.code):
            self.cmd[self.code[self.pc]]()
            self.pc += 1 # move program counter.

def py_brainfuck(argc, argv):
    ibf = BrainFuck()
    if argc > 1:
        for f in argv:
            with open(f, 'r') as fp:
                code = fp.read() # ''.join(fp.readlines())
                ibf.run(fp.read())
    else:
        while True:
            code = input('>>> ')
            if len(code) == 0: break
            else: ibf.run(code)

if __name__ == '__main__':
    py_brainfuck(len(sys.argv), sys.argv[1:])
