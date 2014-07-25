#!/usr/bin/python

from sys import stdin

def IsAsc(s, i, j):
    t = s[i:j]
    t.reverse()
    t = s[:i]+t+s[j:]
    i = 1
    while i < n:
        if t[i-1] > t[i]:
            return False
        i += 1
    return True

n = int(stdin.readline())
a = map(int, stdin.readline().split())

c = 0
i = 0
b, e = -1, -1
while i < n:
    j = i+1
    while j < n and a[j-1] > a[j]:
        j += 1
    if j-i > 1:
        c += 1
        if IsAsc(a, i, j):
            b, e = i+1, j
    i = j

if c == 0:
    b, e = 1, 1

if c < 2 and b != -1:
    print 'yes\n', b, e
else:
    print 'no'
