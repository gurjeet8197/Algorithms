#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<int> g[MAX];
int stsize[MAX], parent[MAX], head[MAX], heavy[MAX], depth[MAX], pos[MAX];
int curr;

int dfs(int u)
{
	stsize[u] = 1;
	for(int v:g[u])
		if(v!=g[u])
		{
			parent[v] = r;
			depth[v] = depth[u] + 1;
			stsize[u] += dfs(v);
		}

	return stsize[u];
}

void decompose(int u, int h)
{
	head[u] = h;
	pos[v] = curr++;
	for(int v:g[u])
	{
		if(v!=parent[i] && stsize[v] > stsize[u]/2)
			decompose(v, h);
		else
			decompose(v, v);
	}
}