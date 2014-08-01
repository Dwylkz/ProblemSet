#!/usr/bin/python

from sys import stdin

def Check(a):
    i = 1
    while i < n:
        if a[i-1] > a[i]:
            return False
        i += 1
    return True

n = int(stdin.readline())
a = map(int, stdin.readline().split())

c = 0
l = 0
i = 0
while i < n:
    j = i+1
    while j < n and a[j-1] <= a[j]:
        j += 1
    c += 1
    l = j-i
    i = j

a = a[(n-l):]+a[:(n-l)]

if c == 1:
    l = 0

if c > 2 or not Check(a):
    l = -1

print l
