//POJ 3903
//User: maximpb
//Memory: 1560K
//Time: 657MS
//Lang: G++
//Submit Time: 2013-07-03 13:36:01

#include <vector>
#include <iostream>

#define INF (1<<31)

using namespace std;

int main(int argc, char* argv[])
{
	int c;
	while(cin>>c)
	{
		vector<int> n;	//input
		vector<int> d;	//d[i] is the smallest number that satisfy l[d[i]] = i where l is the length
		for(int i=0; i<c; i++)
		{
			int t;
			cin>>t;
			n.push_back(t);
		}
		d.resize(n.size()+1);
		
		d[0] = INF;
		d[1] = n[0];
		int maxlen = 1;
		for(int i=1; i<c; i++)
		{
			//binary search maximum j that
			//d[j]<n[i]
			int min = 0;
			int max = maxlen;
			int ans = 0;	
			while(min<=max)
			{
				int mid = (min+max)/2;
				if(d[mid]<n[i])
				{
					ans = mid;
					min = mid+1;
				}
				else
				{
					max = mid-1;
				}
			}
			if(ans+1 > maxlen)
			{
				d[ans+1] = n[i];
				maxlen++;
				
			}
			else if(n[i]<d[ans+1])
			{
				d[ans+1]=n[i];
			}
		}
		cout<<maxlen<<endl;
	}
	
	return 0;
}
