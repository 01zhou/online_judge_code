//ZOJ 2724
//Lang: C++
//Run Times: 1140
//Run Memory: 1176
//User Name: 01zhou

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Msg
{
public:
	string str;
	int param;
	int pr;
	bool operator() (const Msg& m1, const Msg& m2) const
	{
		return((m1.pr) > (m2.pr));
	}
};

int main(int argc, char* argv[])
{
	priority_queue<Msg, vector<Msg>, Msg> q;
	string op;
	Msg m;
	while(cin>>op)
	{
		if(op.compare("GET")==0)
		{
			if(q.empty())
				cout<<"EMPTY QUEUE!"<<endl;
			else
			{
				cout<<q.top().str<<" "<<q.top().param<<endl;
				q.pop();
			}
		}
		else
		{
			cin>>m.str>>m.param>>m.pr;
			q.push(m);
		}
	}
	return 0;
}
