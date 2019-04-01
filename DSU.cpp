#include <bits/stdc++.h>
using namespace std;

#define MAX 10000;
int p[MAX]; // store the parent of index

void make(int v)
{
	p[v] = v;
}

void find(int v)
{
	if(p[v] == v)
		return v;
	else 
		return find_set(p[v]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a!=b)
		p[b] = a ; // or p[a] = b but any one only
}