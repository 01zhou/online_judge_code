#!python
#ZOJ: 3714
#LANG: Python

import sys

t = int(sys.stdin.readline())
for i in range(t):
 	[n, m] = list(map(int, sys.stdin.readline().split()))
	J = list(map(int, sys.stdin.readline().split()))
	if n==m:
		print(sum(J))
	else:
		now = sum(J[0:m])
		best = now
		for j in range(n):
			now += J[(m+j)%n]
			now -= J[j%n]
			if now>best:
				best = now
		print(best)
			
