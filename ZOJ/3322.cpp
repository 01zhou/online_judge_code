//ZOJ3322
//LANG: C++
#include <iostream.h>
main()
{
	int t;
	int y1,m1,d1,y2,m2,d2,ans;
	cin>>t;
	while(t--)
	{
		cin>>y1>>m1>>d1>>y2>>m2>>d2;
		ans=(y1*1000+m1*50+d1)-(y2*1000+m2*50+d2);
		if(ans<0)
			cout<<"javaman\n";
		if(ans>0)
			cout<<"cpcs\n";
		if(ans==0)
			cout<<"same\n";
	}
}
