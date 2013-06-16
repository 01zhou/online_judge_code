//01zhou
//16 Jun 2013

#include <algorithm> 
#include <vector>

using namespace std;

class EllysPairs
{
public:
	int getDifference(vector <int> knowledge)
	{
		int size = knowledge.size();
		sort(knowledge.begin(), knowledge.end());
		int min, max;
		min = max = knowledge[0] + knowledge[size-1];
		for(int i=1; i<size-i-1; i++)
		{
			int sum = knowledge[i]+knowledge[size-i-1];
			if(sum<min)
				min = sum;
			if(sum>max)
				max = sum;
		}
		return max-min;
	}
};
