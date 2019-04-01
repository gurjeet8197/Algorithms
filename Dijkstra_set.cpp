#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

vector<pii> g[100];
int n;
vi d;

void addEdge(int u, int v, int w) 
{ 
    g[u].push_back(make_pair(v, w)); 
    g[v].push_back(make_pair(u, w)); 
} 

void dijkstra(int source)
{
	set<pii> s;
	d.assign(n, INF);

	s.insert(mp(0, source));
	d[source] = 0;

	while(!s.empty())
	{
		pii cur = *(s.begin());
		s.erase(s.begin());
		int u = cur.second;

		for(auto next:g[u]){
			int v = next.first;
			int w = next.second;
			if(d[v] > d[u] + w){
				if(d[v]!=INF)
					s.erase(s.find(mp(d[v], v)));

				d[v] = d[u] + w;
				s.insert(mp(d[v], v));
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
    cout << d[i] << endl; 
  
    return 0; 
} 
