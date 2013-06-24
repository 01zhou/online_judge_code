//ZOJ 2770
//LANG: C++

#include <stdio.h>
#include <stdlib.h>

int edge_u[20000];
int edge_v[20000];
int edge_w[20000];
int dist[2000];
int null[2000];

int main(int argc, char* argv[])
{
  int n, m;
	int t1,t2,t3;
	int eid;
	while(fscanf(stdin, "%d %d", &n, &m)!=EOF)
	{
		eid = 0;
		for(int i=1; i<n+2; i++)
		{
			edge_u[eid] = 0;
			edge_v[eid] = i;
			edge_w[eid] = 0;
			eid++;
		}
		for(int i=2; i<n+2; i++)
		{
			edge_u[eid] = i;
			edge_v[eid] = i-1;
			edge_w[eid] = 0;
			eid++;
		}
		for(int i=0; i<n; i++)
		{
			fscanf(stdin, "%d", &t1);
			edge_u[eid] = i+1;
			edge_v[eid] = i+2;
			edge_w[eid] = t1;
			eid++;
		}
			
		for(int i=0; i<m; i++)
		{
			fscanf(stdin, "%d %d %d", &t1, &t2, &t3);
			edge_u[eid] = t2+1;
			edge_v[eid] = t1;
			edge_w[eid] = -t3;
			eid++;
		}
		
		//BF
		//init
		for(int i=0; i<n+2; i++)
		{
			null[i] = 1;
		}
		null[0]	= 0;
		dist[0] = 0;
		
		//relax
		for(int i=0; i<n+1; i++)
		{
			for(int j=0; j<eid; j++)
			{
				int u = edge_u[j];
				int v = edge_v[j];
				int w = edge_w[j];
				if((null[v] == 1 && null[u] == 0))
				{
					null[v] = 0;
					dist[v] = dist[u]+w;
				}
				else if(null[v]==0 && null[u] == 0)
				{
					if(dist[v]>dist[u]+w)
					{
						dist[v] = dist[u]+w;
					}
				}
				
			}
		}
		
		//check negative
		int flag = 0;
		for(int i=0; i<eid; i++)
		{
			int u = edge_u[i];
			int v = edge_v[i];
			int w = edge_w[i];
			if((null[v] == 1 && null[u] == 0))
			{
				flag = 1;
				break;
			}
			else if(null[v]==0 && null[u] == 0)
			{
				if(dist[v]>dist[u]+w)
				{
					flag = 1;
					break;
				}
			}
		}
		
		if(flag == 1)
			fprintf(stdout, "Bad Estimations\n");
		else
		{
			fprintf(stdout, "%d\n", dist[n+1]-dist[1]);
		}
	}
}
