#! /usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'He Tao'

'''
docx2txt: Transfer Office Open XML(.docx) file to txt.

Reference: 
    https://msdn.microsoft.com/en-us/library/dd773189(v=office.12).aspx
'''

from zipfile import ZipFile
from html.parser import HTMLParser

def xml2txt(text):
    class Parser(HTMLParser):
        def __init__(self):
            HTMLParser.__init__(self)
            self.text = ''
        def handle_endtag(self, tag):
            if tag == 'w:p':  # new line
                self.text += '\n'
        def handle_data(self, data):
            self.text += data
    xmlp = Parser()
    xmlp.feed(text)
    xmlp.close()
    return xmlp.text

def docx2txt(file):
    zf = ZipFile(file)
    if not zf.namelist().__contains__('word/document.xml'):
        print('invalid MS word file.')
        return None
    text = str(zf.read('word/document.xml'), encoding='utf-8')
    return xml2txt(text)

if __name__ == '__main__':
    print(docx2txt('java.docx'))
