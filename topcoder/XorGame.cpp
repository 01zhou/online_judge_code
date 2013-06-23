//01zhou
//Jun 23 2013

#include <string>

using namespace std;

class XorGame
{
public:
	int play(string S, string E)
	{
		if(S.compare(E)==0)
			return 0;
		int l = S.size();
		for(int i=0; i<l; i++)
		{
			if(S[i]!=E[i])
				S[i] = '1';
			else
				S[i] = '0';
		}
		int c=0;
		for(int i=1; i<l; i++)
			if(S[i]!=S[i-1])
				c++;
		if(c<=1)
			return 1;
		if(c==2 && S[0]=='0')
			return 1;
		if(l<=4)
			return 2;
		return -1;
		
	}
};
