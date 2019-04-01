#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<ii> g[100];
int n;
vi dis;

void addEdge(int u, int v, int w) 
{ 
    g[u].push_back(make_pair(v, w)); 
    g[v].push_back(make_pair(u, w)); 
} 

void dijkstra(int s)
{
	priority_queue<ii, vector<ii>, greater<ii> > q;
	dis.assign(n, INF);
	dis[s] = 0;
	q.push({0, s});
	while(!q.empty()){
		int curr = q.top().second;
		q.pop();
		for(auto next : g[curr]){
			int v = next.first;
			int w = next.second;
			if(dis[v] > dis[curr] + w){
				dis[v] = dis[curr] + w;
				q.push({dis[v], v});
			}
		}
	}
}


int main() 
{ 
	n = 9;
    cout << n;

    addEdge(0, 1, 4); 
    addEdge(0, 7, 8); 
    addEdge(1, 2, 8); 
    addEdge(1, 7, 11); 
    addEdge(2, 3, 7); 
    addEdge(2, 8, 2); 
    addEdge(2, 5, 4); 
    addEdge(3, 4, 9); 
    addEdge(3, 5, 14); 
    addEdge(4, 5, 10); 
    addEdge(5, 6, 2); 
    addEdge(6, 7, 1); 
    addEdge(6, 8, 6); 
    addEdge(7, 8, 7); 
  
    dijkstra(0);

   for(int i=0; i<9; i++)
    cout << dis[i] << endl; 
  
    return 0; 
} 





