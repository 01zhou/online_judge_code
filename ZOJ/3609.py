#ZOJ 3609
#LANG: Python
import sys;

n = sys.stdin.readline()

for i in range(int(n)):
  line = sys.stdin.readline()
	[a, b] = line.split( )
	if int(b)==1:
		print("1")
	else:
		flag = 0
		for j in range(int(b)):
			if int(a)*j%int(b) == 1:
				print(j)
				flag = 1
				break
		if flag==0:
			print("Not Exist")
