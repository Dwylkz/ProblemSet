#!/usr/bin/python

from sys import stdin

n = int(stdin.readline())
a = map(int, stdin.readline().strip().split())

l = [0]*n
l[0] = 1
for i in xrange(1, n):
    if a[i-1] < a[i]:
        l[i] = l[i-1]+1
    else:
        l[i] = 1

r = [0]*n
r[n-1] = 1
for i in xrange(n-2, -1, -1):
    if a[i] < a[i+1]:
        r[i] = r[i+1]+1
    else:
        r[i] = 1

res = 0
for i in xrange(n):
    res = max(res, l[i], r[i])
    if i > 0:
        res = max(res, l[i-1]+1)
    if i < n-1:
        res = max(res, 1+r[i+1])
    if 0 < i < n-1 and a[i+1]-a[i-1] > 1:
        res = max(res, l[i-1]+1+r[i+1])

print res
