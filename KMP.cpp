#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

void lpsarray(char p[], int m, int lps[]);

int min(int a, int b)
{
	return a>b?b:a;
}

int max(int a, int b)
{
	return a>b?a:b;
}

void kmp(char t[], char p[])
{	
	int n = strlen(t);
	int m = strlen(p);
	int lps[m];
	lpsarray(p, m, lps);

	int j=0;
	for(int i=0; i<n; i++)
	{
		if(t[i]==p[j])
			j++;
		else{
			if(j!=0)
				j = lps[j-1];
		}

		if(j==m){
			
			cout << "string matched at " << i-j+1 << '\n';
			j = lps[m-1];
		}


	}
}



void lpsarray(char p[], int m, int lps[])
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

int main()
{
	char t[] = "ABABDABACDABABCABAB"; 
    char p[] = "ABABCABAB"; 

    kmp(t, p); 
	
}