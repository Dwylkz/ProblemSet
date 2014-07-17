#!/usr/bin/python

from sys import stdin

plus  = lambda x, y: x+y
a = reduce(plus, map(int, stdin.readline().split()))
b = reduce(plus, map(int, stdin.readline().split()))
n = int(stdin.readline())

if (a+4)/5+(b+9)/10 <= n:
    print 'YES'
else:
    print 'NO'
