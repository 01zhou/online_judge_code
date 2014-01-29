#ZOJ 3706
#LANG Python

import sys

def getNumber(n1, n2, n3):
    d = {}
    pos = [-1, 0, 1]
    for p1 in pos:
        for p2 in pos:
            for p3 in pos:
                d[p1*n1+p2*n2+p3*n3] = 1
    return d.__len__()/2 

lines = sys.stdin.readlines()
t = int(lines.pop(0))
for line in lines:
    a, b = map(int, line.split())
    ans = 0
    for n1 in range(1, a):
        n2 = a-n1
        n3 = b
        ans = max(ans, getNumber(n1, n2, n3))

    for n1 in range(1, b):
        n2 = b-n1
        n3 = a
        ans = max(ans, getNumber(n1, n2, n3))

    print ans

        
        
