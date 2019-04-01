#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define int long long
#define pi 2*acos(0.0)
#define MAX 100001
#define pb push_back
#define mk make_pair
#define sortd(arr,n) sort(arr, arr+n, greater<int>())
#define ll long long
#define ull unsigned long long
#define fl(i,k,n) for(int i=k; i<n; i++)
#define setarr(arr,val) memset(arr, val, sizeof(arr))
#define gcd(a,b) __gcd(a,b)
#define printd(ans, p) cout << setprecision(p) << ans
#define mod 1000000007 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define N 111

struct mat{
	int a[N][N];
	int r,c;
	mat(int ar, int ac)
	{
		r = ar, c = ac;
		memset(a,0,sizeof(a));
	}
};

mat operator * (mat x, mat y)
{
	mat z(x.r, y.c);
	for(int i=0; i<z.r; i++)
		for(int j=0; j<z.c; j++)
		{
			for(int k=0; k<x.c; k++)
				z.a[i][j] += (x.a[i][k]*y.a[k][j]);
				
		}

	return z;
}

mat operator ^ (mat  x, int p)
{
	mat y(x.r, x.r);
	for(int i=0; i<x.r; i++)
		y.a[i][i]=1;
	
	while(p)
	{
		if(p&1) y = y*x;
		
		x = x*x;
		p = p>>1;
	}

	return y;
}






main()
{
	
	FASTIO;

	
	
	
}