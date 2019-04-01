#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 10000

//adjacency list
int N;
int g[MAX][MAX];
int rgraph[MAX][MAX];
//bool vis[MAX];
int parent[MAX];
int s, t;

bool bfs()
{
	bool vis[N];
	memset(vis, 0, sizeof(vis));
	fill(parent, parent+N, -2);
	
	queue<int> q;
	q.push(s);
	vis[s] = true;
	parent[s] = -1;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(int i=0; i<N; i++)
			if(vis[i]==false && rgraph[curr][i]>0)
			{
				q.push(i);
				parent[i] = curr;
				vis[i] = true;
			}
	}

	return (vis[t]);
}

int fordfulkerson()
{
	int i, j;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			rgraph[i][j] = g[i][j];

	int maxflow = 0;

	while(bfs())
	{
		
		int flow = INT_MAX;
		for(i=t; i!=s; i=parent[i])
		{
			j = parent[i];
			flow = min(flow, rgraph[j][i]);
		}

		for(i=t; i!=s; i=parent[i])
		{
			j = parent[i];
			rgraph[j][i] -=flow;
			rgraph[i][j] +=flow;
		}
		
		maxflow = maxflow + flow;
	}

	return maxflow;
}

int main() 
{ 
    N = 6;
    s = 0;
    t = 5;
 for(int i=0; i<N; i++)
 	for(int j=0; j<N; j++)
 		//scanf("%d", g[i][j]);
 		{cin >> g[i][j];
 			cout << g[i][j] << " ";
 		}

 	  
  
    cout << "The maximum possible flow is " << fordfulkerson(); 
  
    return 0; 
} 