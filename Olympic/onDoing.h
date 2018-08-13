#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <fstream>
#include <string.h>

using namespace std;

#define mod 10000009ll
#define fori(n) for(ll i= 1; i <= n; i++)
#define forj(n) for(ll j= 1; j <= n; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;
typedef priority_queue<ll> pqmax;
typedef priority_queue<long, vector<long>, greater<long> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y;
ll n= 0, k= 0, a, b, s;
ll test;
bool kt;

string s1, s2;

int main()
{
    cin >> test;

    while( test-- )
	{
        cin >> s;

        cin >> s1 >> s2;

		m= 0;
		for(int i= 0; i < s1.length(); i++)
		{
			t= 0;
			int j, k= 0;
			for(j= 0; j+k < s2.length(); j++)
			{
				if( i+j+k >= s1.length() )
				{
					if( j-k+1 > m )		m= j-k+1;
					break;
				}
				if( s2[j+k] != s1[i+j+k] )	t++;
				if( t > s )
				{
					do {
                        k++;
					}
					while( s2[k] == s1[i+j+k] );
					t--;
				}
			}
			if( j-k-1 > m )		m= j-k-1;
		}

		for(int i= 1; i < s2.length(); i++)
		{
			t= 0;
			int j, k= 0;
			for(j= 0; j+k < s1.length() && t <= s; j++)
			{
				if( i+j+k >= s2.length() )
				{
					if( j-k+1 > m )		m= j-k+1;
					break;
				}
				if( s1[j+k] != s2[i+j+k] )	t++;
				if( t > s )
				{
					do {
                        k++;
					}
					while( s1[k] == s2[i+j+k] );
					t--;
				}
			}
			if( j-k-1 > m )		m= j-k-1;
		}

		cout << m << endl;
	}
}

