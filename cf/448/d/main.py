#!/usr/bin/python

from sys import stdin

s = map(int, stdin.readline().split())
n, m, k = s[0], s[1], s[2]
if n < m:
    swap(n, m)

for i in xrange(1, n+1):
    for j in xrange(1, m+1):
        print '%3d'%(i*j), 
    print ''

print n, m, k
