#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 10000

int N;
typedef pair<int, int> ii;
bool vis[MAX];
vector<pair<int, int>> g[MAX], tree[MAX];

void addEdge(int u, int v, int w) 
{ 
    g[u].push_back(make_pair(v, w)); 
    g[v].push_back(make_pair(u, w)); 
} 

int primMST(int source)
{
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(make_pair(0, source));

	long long minCost = 0;

	while(!pq.empty())
	{
		int curr = pq.top().second;
		int currw = pq.top().first;
		pq.pop();

		if(vis[curr])
			continue;
		vis[curr] = true;
		minCost = minCost + currw;

		for(int i=0; i<g[curr].size(); i++)
		{
			int x = g[x][i].second;
			if(vis[x]==false)
				pq.push(adj[x][i]);

		}
	}


	return minCost;
}


