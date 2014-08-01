#!/usr/bin/python

from sys import stdin

n = int(stdin.readline())
buf = []
for i in xrange((n+1)/2):
    mid = i*2+1
    side = (n-(i*2+1))/2
    buf.append('*'*side + 'D'*mid + '*'*side)

for i in xrange((n+1)/2-2, -1, -1):
    buf.append(buf[i])

for i in buf:
    print i
