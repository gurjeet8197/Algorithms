#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<int> g[MAX];
vector<int> gr[MAX];
stack<int> order;
vector<bool> vis;
vector<vector<int>> scc;
int N;




void find_rgraph(int N)
{
	for(int i=0; i<N; i++)
		for(auto j:g[i])
			gr[j].push_back(i);
	
}

void dfs1(int u)
{
	vis[u] = true;
	for(auto v : g[u])
		if(!vis[v])
			dfs1(v);

	order.push(u);
	
}

void dfs2(int u, vector<int> &cc)
{
	vis[u] = true;
	cc.push_back(u);
		for(auto v : gr[u])
		if(!vis[v])
			dfs2(v, cc);

}

int main()
{

	int m;
	cin >> N >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	find_rgraph(N);

	vis.assign(N, false);
	for(int i=0; i<N; i++)
		if(!vis[i])
			dfs1(i);

	vis.assign(N, false);

	while(!order.empty()){
		int u = order.top();
		order.pop();
		if(!vis[u]){
			vector<int> cc;
			dfs2(u, cc);
			scc.push_back(cc);
		}
	}

	for(int i=0; i<scc.size(); i++){
		for(int j=0; j<scc[i].size(); j++)
			cout << scc[i][j] << " ";
		cout << '\n';
	}

}