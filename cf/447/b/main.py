#!/usr/bin/python

from sys import stdin

s = stdin.readline().strip()
k = int(stdin.readline().strip())
h = map(int, stdin.readline().strip().split())

res = 0
a = max(h)
for i in xrange(len(s)):
    res += h[ord(s[i])-ord('a')]*(i+1)

for i in xrange(len(s), len(s)+k):
    res += a*(i+1)

print res
