//ZOJ3432
//LANG: C
#include <stdio.h>
main()
{
  int n;
	char sock[7];
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		for(i=0;i<7;i++)
			sock[i]=0;
		for(i=0;i<2*n-1;i++)
		{
			getchar();
			for(j=0;j<7;j++)
			{
				char c=getchar();
				sock[j]^=c;
			}
		}
		for(i=0;i<7;i++)
			printf("%c",sock[i]);
		printf("\n");
		
	}
	return(0);
}
