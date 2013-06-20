//ZOJ3323
//LANG: C++
#include <iostream.h>
main()
{
	int i,t;
	cin>>t;
	char psw[21];
	while(t--)
	{
		cin>>psw;
		for(i=0;psw[i]!=0;i++)
			if(psw[i]<'0'||psw[i]>'9')
				cout<<psw[i];
		cout<<endl;
	}
}
