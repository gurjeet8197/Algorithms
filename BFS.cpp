#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<int> g[MAX];
int N;
bool vis[MAX];
int dist[MAX];

void addEdge(int u, int v) 
{ 
    g[u].push_back(v); 
    g[v].push_back(u); 
} 
 
  
void bfs(int u) 
{ 
    queue<int> q; 
  
    q.push(u); 
    vis[u] = true; 
    dist[u]=0;
  
    while (!q.empty()) { 
  
        int curr = q.front(); 
        q.pop(); 
        cout << curr << " "; 
   
        for (auto i : g[curr]) { 
            if (!vis[i]) { 
                q.push(i); 
                vis[i] = true; 
                dist[i]=dist[curr]+1;
            } 
        } 
    } 
} 
  

int main() 
{ 
    int V = 5; 
  
    addEdge(0, 1); 
    addEdge(0, 4); 
    addEdge(1, 2); 
    addEdge(1, 3); 
    addEdge(1, 4); 
    addEdge(2, 3); 
    addEdge(3, 4); 
    bfs(0); 
    return 0; 
}