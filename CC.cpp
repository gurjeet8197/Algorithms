#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<int> graph[MAX];
vector<int> comp;
int N;
bool visited[MAX];

void addEdge(int u, int v) 
{ 
    graph[u].push_back(v); 
    graph[v].push_back(u); 
} 

void dfs(int u)
{
	visited[u] = true;
	comp.push_back(u);
	for(int i=0; i<graph[u].size(); i++){
		int v = graph[u][i];
		if(!visited[v])
			dfs(v);
	}
}

void scc()
{
	for(int i=0; i<N; i++)
		if(!visited[i]){
			comp.clear();
			dfs(i)
			cout << "component" << ;
			for(int j=0; j<comp.size(); j++)
				cout << " " << comp[j];
			cout << endl;
		}

}