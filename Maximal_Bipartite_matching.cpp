#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
#define INF 10000
vector<int> g[MAX];
int n, m, match[MAX], dist[MAX];
// indexing starts from 1

bool bfs()
{
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(match[i]==0)
		{
			dist[i] = 0;
			q.push(i);
		}
		else
			dist[i] = INF;

	dist[0] = INF;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		if(u!=0)
		{
			for(int v : g[u])
				if(dist[match[v]]==INF)
				{
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
		}
	}

	return (dist[0]!=INF);

}

bool dfs(int u)
{
	if(u!=0)
	{
		for(int v : g[u])
			if(dist[match[v]]==dist[u] + 1 && dfs(match[v]))
			{
				match[v] = u;
				match[u] = v;
				return true;
			}
		dist[u] = INF;
		return false;
	}

	return true;
}

int hopcroft_karp()
{
	int matching = 0;
	while(bfs())
	{
		for(int i=1; i<=n; i++)
			if(match[i] == 0 && dfs(i))
				matching++;
	}
	return matching;
}

int main()
{
	cin >> n >> m >> e;
	for(int i=0; i<e; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v+n);
	}

	cout << hopcroft_karp();
}