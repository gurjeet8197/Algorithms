#include <bits/stdc++.h>
using namespace std;

#define MAX 10000;
int p[MAX], size[MAX];

void make(int v)
{
	p[v] = v;
	size[v] = 1;
}

int find(int v)
{
	if(p[v] == v)
		return v;
	else
		return p[v] = find(p[v]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a!=b){
		if(size[a]>size[b]){
			parent[b] = a;
			size[a] += size[b];
		}

		else{
			parent[a] = b;
			size[b] += size[a];
		}
	}
}