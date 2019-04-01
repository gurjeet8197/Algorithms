#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 10000

struct edge{
	int a, b, w; //edge a->b with weight w
}

vector<edge> e;
vector<int> d;
vector<int> p;
int n, m;
bool negative_cycle;

void bellman_ford(int s)
{
	d.assign(n, INF);
	p.assign(n, -1);
	d[s] = 0;

	int u, v, wt;

	for(int i=0; i<n-1; i++)
		for(int j=0; j<m; j++){
			u = e[j].a;
			v = e[j].b;
			wt = e[j].w;
			if(d[u]!=INF){
				d[v] = min(d[v], d[u] + wt);
				p[v] = u;
			}
		}

	//check negative cycle
	negative_cycle=false; //assume
	for(int i=0; i<m; i++){
		u = e[j].a;
		v = e[j].b;
		wt = e[j].w;
		if(d[u]!=INF && d[v] > d[u] + wt){
			negative_cycle = true;
			break;
		}
	}
}

vector<int> find_path(int t){
	if(d[t]==INF)
		return; // no path from s to t

	vector<int> path;
	for(int t=v; t!=-1; t=p[t] )
		path.push_back(t);

	reverse(path.begin(), path.end());
	return path;
}


void bellman_ford_optimised(int s) // if there is negative cycle then it will go into infinite loop
{
	d.assign(n, INF);
	d[s] = 0;
	while(1){
		bool flag = false;
		for(int i=0; i<m; i++){
			int u = e[j].a;
			int v = e[j].b;
			int wt = e[j].w;
			if(d[u]!=INF)
				if(d[v] > d[u] + wt){
					d[v] = d[u] + wt;
					flag = true;
			}
		}

		if(!flag)
			break;
	}
}

