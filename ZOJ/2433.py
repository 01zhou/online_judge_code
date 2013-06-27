import sys;

t = int(sys.stdin.readline())
for i in range(t):
  if i!=0:
		print

	sys.stdin.readline()
	n = int(sys.stdin.readline())
	c = list(map(int, sys.stdin.readline().split()))
	
	if n < 4:
		print("0")
	else:
		
		id = 1
		dis = c[1] - c[0]
		for j in range(2, len(c)-1):
			if c[j]-c[j-1] < dis:
				dis = c[j]-c[j-1]
				id = j
				
		print(c[-1]+dis)
		print(str(id+2)+" 1 "+str(len(c)+1)+" "+str(id+1))
