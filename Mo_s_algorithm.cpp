#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
int size;
int n;
int a[MAX];

struct query
{
	int l, r, idx;
	bool operator < (query other) const
	{
		return make_pair(l/size, r) < make_pair(other.l/size, other.r);
	}
};

vector<int> mos(vector<query> q)
{
	vector<int> ans(q.size());
	size = (n)sqrt(n);
	sort(q.begin(), q.end());

	int cl = 0, cr = -1;
	int sum = 0;

	for(query i : q)
	{
		int l = i.l, r = i.r;

		while(cl < l)
		{
			sum -= a[cl];
			cl--;
		}

		while(cl > l)
		{
			sum += a[cl];
			cl++;
		}

		while(cr < r)
		{
			sum += a[cr];
			cr++;
		}

		while(cr > r)
		{
			sum -= a[cr];
			cr--;
		}

		ans.push_back(sum);
	}

	return ans;
}