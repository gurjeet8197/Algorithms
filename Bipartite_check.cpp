#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int n, m;
vector<int> g[MAX];
bool vis[MAX];
int col[MAX];

bool bipartite_check(int src)
{
	queue<int> q;
	q.push(src);
	vis[src] = true;
	col[src] = 0;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int v : g[u])
		{
			if(!vis[v])
			{
				q.push(v);
				vis[v] = true;
				if(col[u]==0)
					col[v] = 1;
			}

			else if (col[u] == col[v])
				return false;
		}
	}

	return true;
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

	if(bipartite_check(1))
		cout << "Yes";
	else 
		cout << "No";
}