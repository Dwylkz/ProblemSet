#!/usr/bin/python2.7
from sys import stdin

n, m = [int(x) for x in stdin.readline().split()]
a = [int(x) for x in stdin.readline().split()]

def f(i, r):
    if i == n:
        return int(r<m)
    elif r == 0:
        return 1+f(i, m)
    elif a[i] <= r:
        return f(i+1, r-a[i])
    else:
        return 1+f(i, m)

print f(0, m)
