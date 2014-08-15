#!/usr/bin/python

from sys import stdin

x1, y1, x2, y2 = map(int, stdin.readline().split())

if x1 == x2 and y1 == y2:
    print -1
    exit(0)

if x1 == x2:
    x = x1+abs(y1-y2)
    print x, y1, x, y2
    exit(0)

if y1 == y2:
    y = y1+abs(x1-x2)
    print x1, y, x2, y
    exit(0)

h = abs(x1-x2)
v = abs(y1-y2)
if h != v:
    print -1
    exit(0)

print x1, y2, x2, y1
