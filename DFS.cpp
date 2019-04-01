#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<int> g[MAX];
int N;
bool vis[MAX];

void addEdge(int u, int v) 
{ 
    g[u].push_back(v); 
    g[v].push_back(u); 
} 


void dfs(int u)
{
	vis[u] = true;
	cout << u << " ";
	for(int v : g[u]){
		if(vis[v] == false)
			dfs(v);
    }
}




int main() 
{ 
    int V = 5; 
    //vector<int> g[V]; 
  
    addEdge(0, 1); 
    addEdge(0, 4); 
    addEdge(1, 2); 
    addEdge(1, 3); 
    addEdge(1, 4); 
    addEdge(2, 3); 
    addEdge(3, 4); 
    for(int u=0; u<V; u++)
        if(vis[u]==false)
            dfs(u);
    return 0; 
} 