#!python

#ZOJ 2772
#Lang: Python
#Run Time: 20
#Run Memory: 320
#User Name: 01zhou

import sys

t = int(sys.stdin.readline())
for i in range(t):
	c = int(sys.stdin.readline())
	q = int(c/25)
	c %= 25
	d = int(c/10)
	c %= 10
	n = int(c/5)
	c %= 5
	p = c
	print("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)" % (i+1, q, d, n, p))
