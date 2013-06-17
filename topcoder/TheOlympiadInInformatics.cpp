//01zhou
//Jun 17 2013

#include <vector>
#include <stdio.h>
using namespace std;

class TheOlympiadInInformatics
{
public:
  int find(vector <int> sums, int k)
	{
		int min = 0;
		int max = (1<<30);
		
		int ans = 0;
		
		while(min<=max)
		{
			int mid = (min + max) / 2;
			
			//check if mid is OK
			int g=0;
			for(int i=0; i<=sums.size(); i++)
			{
				g+=sums[i]/(mid+1);
			}
			fprintf(stderr, "%d %d\n", mid, g);
			if(g>k)
			{
				min=mid+1;
			}
			else
			{
				ans = mid;
				max = mid-1;
			}
			
		}
		
		return ans;
	}
};
