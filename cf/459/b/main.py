#!/usr/bin/python

from sys import stdin

n = int(stdin.readline())
bs = map(int, stdin.readline().split())

bs.sort();

diff = bs[-1]-bs[0]

if (diff == 0):
    print diff, n*(n-1)//2
    exit(0)

l = 1
while l < n and bs[l-1] == bs[l]:
    l += 1

r = 1
while r > 0 and bs[n-r-1] == bs[n-r]:
    r += 1

print diff, l*r
