//01zhou
//Jun 17 2013

#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

class EllysReversals
{
public:
  int getMin(vector <string> words)
	{
		for(int i=0; i<words.size(); i++)
		{
			//sort letters in words[i];
			//in pair
			for(int j=0;j+1<words[i].size();j+=2)
			{
				if(words[i][j]>words[i][j+1])
				{
					char t = words[i][j];
					words[i][j]=words[i][j+1];
					words[i][j+1]=t;
				}
			}
		
			fprintf(stderr, "%s\n", words[i].c_str());
			
			//between pairs
			//bubble
			bool flag =true;
			while(flag)
			{
				flag = false;
				for(int j=0; j+3<words[i].size(); j+=2)
				{
					if(words[i][j]>words[i][j+2] || (words[i][j]==words[i][j+2] && words[i][j+1]>words[i][j+3]))
					{
						char t;
						t = words[i][j];
						words[i][j] = words[i][j+2];
						words[i][j+2] = t;
						t=words[i][j+1];
						words[i][j+1] = words[i][j+3];
						words[i][j+3] = t;
						flag = true;
					}
				}
			}
			fprintf(stderr, "%s\n", words[i].c_str());
			
		}
		for(int i=0; i<words.size()-1; i++)
		{
			if(words[i].empty())
				continue;
			for(int j=i+1; j<words.size(); j++)
			{
				if(words[i].compare(words[j])==0)
				{
					words[i].clear();
					words[j].clear();
					break;
				}
			}
		}
		int sum=0;
		for(int i=0; i<words.size(); i++)
		{
			if(!words[i].empty())
				sum++;
		}
		return sum;
	}
};
