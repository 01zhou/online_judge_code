#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Problem
{
public:
  int p;
	int v;
};

class State
{
public:
	int v;
	int n;
	int p;
	bool isNull()
	{
		return (v<0);
	}
	State solve(Problem prob, int nowtime)
	{
		State newState;
		newState.v = v + prob.v;
		newState.n = n+1;
		newState.p = p+ nowtime + prob.p;
		return newState;
	}	
};

bool comp_s(State a, State b)
{
	if(a.v<b.v)
		return true;
	if(a.v==b.v && a.n<b.n)
		return true;
	if(a.v==b.v && a.n==b.n && a.p>b.p)
		return true;
	return false;
}

bool comp_p(Problem a, Problem b)
{
	if(a.p<b.p)
		return true;
	if(a.p == b.p && a.v > b.v)
		return true;
	return false;
}

int main(int argc, char* argv[])
{
	int c,t,n;
	vector<Problem> problem(50);
	vector<State> timeline(1001);
	
	State null;
	null.v = -1;
	null.n = -1;
	null.p = (1<<30);
	
	State empty;
	empty.v = 0;
	empty.n = 0;
	empty.p = 0;
	
	fscanf(stdin, "%d", &c);
	while(c--)
	{
		fscanf(stdin, "%d %d", &t, &n);
		for(int i=0;i<n; i++)
			fscanf(stdin, "%d", &(problem[i].p));
		for(int i=0;i<n; i++)
			fscanf(stdin, "%d", &(problem[i].v));
		
		timeline[0] = empty;
		for(int i=1; i<=t; i++)
			timeline[i] = null;
		
		sort(problem.begin(), problem.begin()+n, comp_p);
		
		for(int j=0; j<n; j++)
		{
			for(int i=t; i>=0; i--)
			{
				if(timeline[i].isNull())
					continue;
				int newt = i+problem[j].p;
				if(newt >t)
					continue;
				State newState = timeline[i].solve(problem[j], i);
				if(comp_s(timeline[newt], newState))
				{
					timeline[newt] = newState;
				}
			}
		}
		
		State bestState = empty;
		for(int i=t; i>=0; i--)
		{
			if(timeline[i].isNull())
				continue;
			if(comp_s(bestState, timeline[i]))
			{
				bestState = timeline[i];
			}
		}
		
		fprintf(stdout, "%d %d %d\n", bestState.v, bestState.n, bestState.p);
	}
	return 0;
}
