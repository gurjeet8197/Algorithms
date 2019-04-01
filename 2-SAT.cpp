#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<int> g[MAX];
vector<int> gr[MAX];
stack<int> order;
vector<bool> vis;
vector<vector<int>> scc;
int s[MAX];

//2n is total number of nodes
//m total number of clauses
// i -> i and -i -> n+i

void find_rgraph(int n)
{
	for(int i=1; i<=2*n; i++)
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

void dfs2(int u, vector<int> &cc, int count)
{
	vis[u] = true;
	cc.push_back(u);
	s[u] = count;
		for(auto v : gr[u])
		if(!vis[v])
			dfs2(v, cc, count);

}


bool is2sat(int n, int m, int a[], int b[])
{
	for(int i=0; i<m; i++)
	{
		int u, v, un, vn;
		u = a[i]; v = b[i];

		if(u>0)
			un = u + n;
		else
		{
			un = abs(u);
			u = un+ n;
		}

		if(v>0)
			vn = v + n;
		else
		{
			vn = abs(v);
			v = vn+ n;
		}

		g[u].push_back(vn);
		g[v].push_back(un);
	}

	find_rgraph(n);

	vis.assign(2*n+1, false);
	for(int i=1; i<=2*n; i++)
		if(!vis[i])
			dfs1(i);

	int count = 0;
	vis.assign(2*n+1, false);
	while(!order.empty()){
		int u = order.top();
		order.pop();
		if(!vis[u]){
			vector<int> cc;
			dfs2(u, cc, count);
			scc.push_back(cc);
			count++;
		}
	}

	for(int i=1; i<=n; i++)
		if(s[i]==s[i+n])
			return false;

	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int a[m], b[m];
	for(int i=0; i<m; i++)
		cin >> a[i] >> b[i];

	if(is2sat(n, m, a, b))
		cout << "Yes";
	else
		cout << "No";


}