#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
set<int> g[MAX];
int subtree[MAX], parent[MAX];


void dfs(int u, int pu)
{
	nodes++;
	subtree[u] = 1;
	for(auto v:g[u])
		if(v!=pu)
		{
			dfs(v,u);
			subtree[u] += subtree[v];
		}
}

int centroid(int u, int pu)
{
	for(auto v:g[u])
	{
		if(v!=pu && subtree[v] > nodes/2)
			return centroid(v,u);
	}
	return u;
}

void decompose(int u, int pu)
{
	nodes = 0;
	dfs(u,u);
	int node = cetroid(u,u);
	parent[node] = pu;
	for(auto v:g[node])
	{
		g[v].erase(node);
		decompose(v,node);
	}
}