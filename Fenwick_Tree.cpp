#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
int a[1000], bit[1000];
int n;

//index starts from 1

void update(int i, int val)
{
	while(i <= n)
	{
		bit[i] += val;
		i += i & (-i);
	}
}

int prefixSum(int i)
{
	int sum = 0;
	while(i > 0)
	{
		sum += bit[i];
		i -= i & (-i);
	}

	return sum;
}

int rangeSum(int l, int r)
{
	return prefixSum(r) - prefixSum(l-1);
}

void constructBIT()
{
	for(int i=1; i<=n; i++)
		update(i, a[i]);

}

int main()
{
	n = 20;
	for(int i=1; i<=n; i++)
	{
		a[i] = i;
	}

	constructBIT();

	cout << rangeSum(3,4);

}