#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 10000

int g[MAX][MAX], d[MAX][MAX]; // for unconnected nodes store INF in matrix

void floyd_warshall(int n){

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			d[i][j] = g[i][j];

	for(k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


}