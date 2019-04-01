#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int n, m;
vector<int> g[MAX];
vector<int> col;
// 0 -> not visited
// 1 -> is in dfs
// 2 -> dfs finished

bool dfs(int u)
{
	col[u] = 1;
	for(int v : g[u]){
		if(col[v]==0){
			if(dfs(v))
				return true;
		}
		else if(col[v]==1)
			return true;
	}

	col[u] = 2;
	return false;
}
bool cycle()
{	
	col.assign(n,0);
	for(int i=0; i<n; i++)
		if(col[i]==0)
			if(dfs(i))
				return true;

	return false;
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

	if(cycle())
		cout << "Yes";
	else
		cout << "No";
}