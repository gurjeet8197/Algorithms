#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MAX 10000

int n;
vector<vector<int>> cap, flow;
vector<int> height, excess;

void push(int u, int v)
{
	int d = min(excess[u], cap[u][v] - flow[u][v]);
	flow[u][v] += d;
	flow[v][u] -= d;
	excess[u] -= d;
	excess[v] += d;
	
}

void relabel(int u)
{
	int d = INF;
	for(int i=0; i<n; i++)
		if(cap[u][i] - flow[u][i] > 0)
			d = min(d,height[i])
	
	if(d<INF)
		height[u] = d+1;
}

vector<int> mh_vertices(int s, int t)
{
	vector<int> mh;
	for(int i=0; i<n; i++)
		if(i!=s && i!=t && excess[i] > 0)
		{
			if(!mh.empty() && height[i] > height[mh[0]])
				mh.clear();
			if(mh.empty() || height[i] == height[mh[0]])
				mh.push_back(i);
		}

	return mh;
}

int max_flow(int s, int t)
{
	height.assign(n,0);
	height[s] = n;
	flow.assign(n, vector<int>(n,0));
	excess.assign(n,0);
	excess[s] = INF;

	for(int i=0; i<n; i++)
		if(i!=s)
			push(s,i);

	vector<int> curr = mh_vertices(s,t);
	while(!curr.empty())
	{
		for(int i : curr)
		{
			bool pushed = false;
			for(int j=0; j<n && excess[i]; j++)
				if(cap[i][j] - flow[i][j] > 0 && height[i] == height[j] + 1)
					{
						push(i,j);
						pushed = true;
					}
		}

		if(!pushed)
		{
			relabel(i);
			break;
		}

		curr=mh_vertices(s,t);
	}

	int mf = 0;
	for(int i=0; i<n; i++)
		max_flow += flow[s][i];

	return mf;

}