#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int min(int a, int b)
{
	return a>b?b:a;
}

int max(int a, int b)
{
	return a>b?a:b;
}

void lpsarray(string p, int m, int lps[])
{
	lps[0] = 0;
	
	for(int i=1; i<m; i++)
	{
		int j = lps[i-1];
		while(j > 0 && p[j]!=p[i])
			j = lps[j-1];
		if(p[j]==p[i])
			j++;
		lps[i] = j;
	}

	
}

void kmp(string t, string p)
{
	string s = p+'#'+t;
	vector<int> v;
	int m = p.size();
	int n = s.size();
	int lps[n];
	lpsarray(s, n, lps);
	for(int i=0; i<n; i++)
		if(lps[i]==m)
			v.push_back(i-2*m); //i-(m+1)-m+1

	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";

}


int main()
{
	string t= "ABABDABACDABABCABAB"; 
    string p = "ABABCABAB"; 
    cout << t.size()<< " " << t.length() << " ";

    kmp(t, p); 
	
}