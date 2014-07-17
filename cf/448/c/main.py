#!/usr/bin/python

from sys import stdin

n = int(stdin.readline())
a = map(int, stdin.readline().split())
m = min(a)

if a[0] != m:
    s = 1
else:
    s = 0
for i in xrange(1, n):
    if a[i] != a[i-1] and a[i] != m:
        s += 1

print min(n, min(a)+s)
