#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int arr[MAX];
int st[4*MAX];
int n;

void build(int v, int l, int r)
{
	if(l==r)
		st[v] = arr[l];
	else
	{
		int m = (l+r)/2;
		build(v*2, l, m);
		build(v*2+1, m+1, r);
		st[v] = st[v*2] + st[v*2+1];
	}
}

int sum(int v, int l, int r, int ql, int qr)
{
	if(ql>r || qr<l)
		return 0;
	if(l>=ql && r<=qr)
		return st[v];
	int m = (l+r)/2;
	return sum(v*2, l, m, ql, qr)
			+sum(v*2+1, m+1, r, ql, qr);

}

void update(int v, int l, int r, int pos, int val)
{
	if(l==r)
		st[v] =val;
	else{
		int m = (r+l)/2;
		if(pos<=m)
			update(v*2, l, m, pos, val);
		else
			update(v*2+1, m+1, r, pos, val);
		st[v] = st[v*2] + st[v*2+1];
	}
}

void updateRange(int v, int l, int r, int ql, int qr, int add)
{
	if(l>r || l>qr || r<ql)
		return ;
	if(l==r)
	{
		st[v] =+ val;
		return;
	}

	int m=(l+r)/2;
	updateRange(v*2, l, m, ql, qr, add);
	updateRange(v*2+1,m+1,r,ql, qr, add);
	st[v] = st[v*2] + st[v*2+1];
}

int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	build(1, 0, n-1);
	//for(int i=0; i<2*n; i++)
	//	cout << i << " " << st[i]<<' ';
	//cout << sum(1, 0, n-1, 4, 6)<<'\n';
	//update(1,0,n-1,5,3);
	cout << sum(1, 0, n-1, 3, 5)<<'\n';
	//cout << '\n';
	//for(int i=0; i<2*n; i++)
		//cout << i << " " << st[i]<<' ';
}