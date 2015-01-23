#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os, sys

def build(srcdir, builddir):
    filenames = list(os.walk(srcdir, topdown = False))[1][2]
    for f in filenames:
        cmd = 'pandoc %s/%s -o %s/%s.html --mathjax' %(srcdir, f, builddir, f[0:3])
        print(cmd)
        output = os.popen(cmd).read()
        if output.__len__() != 0:
            print(output)
        
if __name__ == '__main__':
    markdowndir = './solutions'
    htmldir = './html'
    build(markdowndir, htmldir)
