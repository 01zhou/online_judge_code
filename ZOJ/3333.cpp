//ZOJ3333
//LANG: C++
#include <iostream.h>
main()
{
  int n,p,pa,pb;
	cin>>n;
	while(n--)
	{
		cin>>p>>pa>>pb;
		p=abs(p-pa)<abs(p-pb)?'A':'B';
		cout<<(char)p<<endl;
	}
	return(0);
}
