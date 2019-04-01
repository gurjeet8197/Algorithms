#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int n, 
int cap[MAX][MAX];
vector<int> g[MAX];

int bfs(int s, int t, int parent[], int n)
{
	fill(parent, parent+n, -1);
	parent[s] = -2;
	queue<int> q;
	int new_flow = INT_MAX;
	q.push(s);

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		for(int i : g[cur]){
			if(parent[i] == -1 && cap[cur][i]>0){
				parent[i] = cur;
				new_flow = min(new_flow, cap[cur][i])
				if(i==t)
					return new_flow;
				q.push(i);
			}
		}
	}

	return 0;
}

int maxflow(int s, int t, int n)
{
	int flow = 0;
	int parent[n];
	int new_flow;

	while(new_flow = bfs(s, t, parent, n)){
		flow = flow + new_flow;

		for(int cur=t; cur!=s; cur=parent[cur]){
			int prev = parent[t];
			cap[prev][cur] -= new_flow;
			cap[cur][prev] += new_flow;
		}
	}

}