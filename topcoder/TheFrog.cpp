//01zhou
//Jun 6 2013

#include <vector>
#define TOO_SMALL 1e-7

using namespace std;
class TheFrog
{
private:
  double abs(double x)
	{
		return x>0?x:-x;
	}

public:
	double getMinimum(int D, vector <int> L, vector <int> R)
	{
		double best = 1;
		//check if step=1 is safe
		for(int i=0; i<L.size(); i++)
		{
			if(R[i] - L[i] != 1)
			{
				best = D;
				break;
			}
		}
		if(best == 1)
			return 1;
		
		int max = 0;
		for(int i=0; i<L.size(); i++)
		{
			if(R[i] - L[i]>max)
				max = R[i]-L[i];
		}
		
		for(int i=0; i<L.size(); i++)
		{
			//for each pit
			for(int step = R[i]-1; step>=1; step--)
			{	
				double stepsize = (double)R[i]/step;
				
				int flag =0;
				if(stepsize >= best)
					break;
				if(stepsize < max)
					continue;
					
				//check if stepsize is safe
				for(int j=0; j<L.size(); j++)
				{

					//check if it will hit pit[i] if using stepsize
					int l = (int)(L[j]/stepsize);
					int r = (int)(R[j]/stepsize);
						
					//int lsafe = (abs(l*stepsize - L[j])>TOO_SMALL);
					if(abs(r*stepsize - R[j])<TOO_SMALL)
					{
						r--;
					}
						
	
					if( abs(r-l)>TOO_SMALL )
					{

						flag = 1;
						break;
					}
				}
				if(flag == 0)
				{
					best = stepsize;
					break;
				}
			}
		}
		return best;
	}
};
