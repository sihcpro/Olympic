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
#include <map>

using namespace std;

#define mod 10000009ll
#define fori(n) for(ll i= 0; i < n; i++)
#define forj(m) for(ll j= 0; j < n; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d", n)
#define outS(s) printf("%s", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;
typedef priority_queue<ll> pqmax;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y;
ll n= 0, k= 0;
ll test;

string s1, s2;

map<ll, bool> a[55];
ll b[50][50];

int main()
{
	cin >> n;

	fori(n)
	{
		forj(n)
		{
			in( b[i][j] );
			if( b[i][j] )a[i][ b[i][j] ]= true;
		}
	}

	fori(n)
	{
		forj(n)
		{
			if( b[i][j] > 1 )
			{
				bool kt1= false;
				for(ll x= 0; x < n && !kt1; x++)
				{
					if( x != i && b[i][j] > b[x][j] )
					{
						if( a[i].find( b[i][j] - b[x][j] ) != a[i].end() )
						{
	//						cout << i << "  " << j << endl;
							kt1= true;
						}
	//					for( ll y= 0; y < n; y++)
	//					{
	//						if( b[i][y] == b[i][j]-b[x][j] )
	//						{
	//							cout << "Yes";
	//							return 0;
	//						}
	//					}
					}
				}
				if( kt1 == false )
				{
//					cout << i << "  " << j << endl;
					cout << "No";
					return 0;
				}
			}
		}
	}

	cout << "Yes";
}
