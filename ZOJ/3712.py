#!python
#01zhou
#ZOJ: 3712
#LANG: Python
#Jun 23 2013

import sys

t = int(sys.stdin.readline())
for i in range(t):
 	[a, b, c] = list(map(int, sys.stdin.readline().split()))
	mymax = c*c*50+(2*c+b)*b*100+(2*c+2*b+a)*a*300
	mymin = a*a*300+(2*a+b)*b*100+(2*a+2*b+c)*c*50
	print("%d %d" % (mymin, mymax))
