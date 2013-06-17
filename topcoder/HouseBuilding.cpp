//01zhou
//Jun 6 2013

#include <vector>
#include <string>

using namespace std;

class HouseBuilding
{
public:
	int getMinimum(vector <string> area)
	{
		int min_e = -1;
		for(char h='0'; h<='8'; h++)
		{
			int e = 0;
			for(int i=0; i<area.size(); i++)
			{
				for(int j=0; j<area[i].size(); j++)
				{
					if(area[i][j] <= h)
						e+= h-area[i][j];
					else
						e+= area[i][j]-h-1;	
				}
			}
			if(min_e < 0 || e<min_e)
				min_e = e;
		}
		return min_e;
	}
};
