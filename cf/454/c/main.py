#!/usr/bin/python

from sys import stdin

m, n = map(int, stdin.readline().split())

res = 0.0
for i in xrange(m, 0, -1):
    p = 1.0/m
    q = (i-1.0)/m
    t = (p+q)**n-q**n
    res += i*t

print res
