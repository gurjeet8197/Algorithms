#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 10000

typedef pair<int, int> ii;

struct edge{
	int u, v, w;
	bool operator< (edge const &other){
		return w < other.w;
	}
};

int n, m;
bool vis[MAX];
vector<pair<int, int>> g[MAX], tree[MAX];
vector<edge> e, emst;

int parent[MAX], size[MAX];

void addEdge(int u, int v, int w) 
{ 
    g[u].push_back(make_pair(v, w)); 
    g[v].push_back(make_pair(u, w));
    edge curr;
    curr.u = u; curr.v = v; curr.w =w;
    e.push_back(curr);

}

void init()
{
	for(int i=1; i<=n; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int v)
{
	while(v!=parent[v])
	{
		parent[v] = parent[parent[v]];
		v = parent[v];
	}

	return v;
}

void union_set(int u, int v)
{
	int pu = find(u);
	int pv = find(v);
	if(pu!=pv){
		if(size[pu] < size[pv])
			swap(pu,pv);
		parent[pv] = pu;
		size[pu] +=size[pv];
		//size[pv] = 0;
	}
}

int kruskalMST()
{
	init();
	int weight = 0;
	sort(e.begin(), e.end());
	for(edge i : e)
	{
		int u=i.u, v=i.v, w=i.w;
		int pu=find(u);
		int pv=find(v);
		if(pu==pv)
			continue;
		weight += w;
		union_set(pu,pv);
		emst.push_back(i);
	}

	return weight;
}

int main()
{
	n = 4, m = 5;
	for(int i=0; i<m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		addEdge(u,v,w);
	}

	kruskalMST();

	cout << emst.size()<<endl;
	for(int i=0; i<emst.size(); i++)
	{
		edge a= emst[i];
		cout << a.u<<" "<<a.v<<" "<<a.w<<endl;
	}

}