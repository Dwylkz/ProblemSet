#!/usr/bin/python

import sys

p, n = map(int, sys.stdin.readline().strip().split())

h = [False]*p

res = -1

for i in xrange(n):
    x = int(sys.stdin.readline().strip())

    if h[x%p] == True and res == -1:
        res = i+1
    h[x%p] = True

print res
