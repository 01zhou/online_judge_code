//01zhou
//Jun 17 2013

#include <vector>
#include <string>
using namespace std;

class EllysFigurines
{
public:
	int getMoves(vector <string> board, int R, int C)
	{
		int w = board[0].size();
		int h = board.size();
		int fw[15];
		int min = w+h;
		for(int i=0; i<board.size(); i++)
		{
			fw[i] = 0;
			for(int j=0; j<board[i].size(); j++)
			{
				fw[i]*=2;
				fw[i]+= (board[i][j] == 'X'?1:0);
			}
		}
		
		for(int i=0; i<(1<<w); i++)
		{
			//if remove the ith(2) cols
			//then check which rows shoule be removed later
			int j = 0; //j = rows id
			for(int k=0; k<h; k++)
			{
				j*=2;
				if( (fw[k] & (~i)) != 0)
					j++;
			}
			// i & j are the cols/rows to remove
			//calculate moves given(i,j)
			int m = 0;
			int ii = i, jj = j;
			while(ii>0)
			{
				if(ii%2!=0)
				{
					ii/=(1<<C);
					m++;
				}
				else
				{
					ii/=2;
				}
			}
			while(jj>0)
			{
				if(jj%2!=0)
				{
					jj/=(1<<R);
					m++;
				}
				else
				{
					jj/=2;
				}
			}
			if(m<min)
			{
				min = m;
			}

			
		}
		return min;
	}
};
