#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<int> g[MAX];
vector<pair<int, int>> bridges;
int n;
bool vis[MAX];
int disc[MAX], low[MAX], int parent[MAX];
int time;


int min(int a, int b)
{
	return a<b?a:b;
}

void dfs(int u)
{
	vis[u] = true;
	disc[u] = low[u] = ++time;

	for(auto i : g[u]){
		if(!vis[i]){
			parent[i] = u;
			dfs(i);
			low[u] = min(low[u], low[i]);
			if(low[i] > disc[u])
				bridges.push_back(make_pair(u,i));
		}

		else if (i!=parent[u]){
			low[u] = min(low[u], disc[i]);
		}
	}
}

void find_bridges()
{
	time = 0;

	 for (int i = 0; i < V; i++) 
    { 
        parent[i] = -1; 
    } 

	for(int i = 0; i<n;i++)
		if(!visited[i])
			dfs(i);
}