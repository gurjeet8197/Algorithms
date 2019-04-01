#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int n, m;
vector<int> g[MAX];
bool vis[MAX];
vector<int> tsort;

void dfs(int u)
{
	vis[u] = true;
	for(int v : g[u])
		if(!vis[v])
			dfs(v);

	tsort.push_back(u);
}

void topological_sort()
{
	for(int i=0; i<n; i++)
		if(!vis[i])
				dfs(i);

	reverse(tsort.begin(), tsort.end());
}

int main()
{
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	topological_sort();

	for(int i=0; i<n; i++)
		cout << tsort[i] << " ";
}