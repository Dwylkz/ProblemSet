#!/usr/bin/python

from sys import stdin

n, m = map(int, stdin.readline().split())
q = (n+m)/2%2
r = (n+m)%2

if q == 1:
    print 'Akshat'
else:
    print 'Malvika'
