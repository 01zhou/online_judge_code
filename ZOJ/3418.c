//ZOJ3418
//LANG: C
#include <stdio.h>
int calcF(int a,int b)
{
  int ans=0,c=a^b;
	while(c>0)
	{
		ans+=c%2;
		c/=2;
	}
	return(ans);
}
main()
{
	int s,m,n;
	scanf("%d",&s);
	while(s--)
	{
		scanf("%d %d",&m,&n);
		int a[100],b[100];
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(int i=0;i<n;i++)
		{
			int ans,ansf=-1;
			for(int j=0;j<m;j++)
			{
				int f=calcF(b[i],a[j]);
				if(f<ansf||ansf==-1)
				{
					ans=a[j];
					ansf=f;
				}
				else if(f==ansf&&a[j]<ans)
					ans=a[j];
			}
			printf("%d\n",ans);
		}
	}
	return(0);
}
