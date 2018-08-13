#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll
#define fori(num) for(ll i= 0; i < num; i++)
#define forj(num) for(ll j= 0; j < num; j++)
#define in(n) scanf("%lld", &n)
#define out(n) printf("%lld\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y, d;
ll n= 0, k= 0, s;
ll test;

string s1, s2;

long a[50005];
long b[50005];
long c[500005];

ll binariSearch(long x, long bot, long top)
{
    long mid= (top + bot)/2;
	if( x == c[mid] )		return mid;
	else if( bot == top )	return mid;
	else if( x < c[mid] )	return binariSearch(x, bot, mid);
	else					return binariSearch(x, mid+1, top);
}

int main()
{
	cin >> n >> m >> x;

	fori(n)		in(a[i]);
	fori(m)		in(b[i]);

	sort(a, a+n);
	sort(b, b+m);

	ll da= 0;
	ll db= 0;
	ll dc= 0;
	c[dc++]= a[da]+ b[db];
	while( dc < 2*x )
	{
		if( ( a[da+1] + b[0] < b[db+1] + a[0] || db + 1 >= m ) && da + 1 < n )
		{
			da++;
			{
				fori(db+1)
				{
					c[dc++]= a[da] + b[i];
				}
			}
		}
		else if( db + 1 < m )
		{
			db++;
			{
				fori(da+1)
				{
					c[dc++]= b[db] + a[i];
				}
			}
		}
		else break;
	}
    sort(c, c+dc);
/*
    fori(da+1)  cout << a[i] << " ";
    cout << endl;
    fori(db+1)  cout << b[i] << " ";
    cout << endl;
    fori(dc)  cout << c[i] << " ";
    cout << endl;
*/
	while( binariSearch( min( a[da] + b[0], a[0] + b[db] ), 0l, dc-1 ) <= x+1 )
	{
		if( ( a[da+1] + b[0] < b[db+1] + a[0] || db + 1 >= m ) && da + 1 < n )
		{
			da++;
			{
			    ll i= 0;
				for(; i <= db; i++)
				{
					s= a[da] + b[i];
					sp= binariSearch(s, 0l, dc-i-1);
					if( sp <= x+1 )	c[dc++]= s;
					else			break;
				}
                sort(c, c+dc);
			}
		}
		else if( db + 1 < m )
		{
			db++;
			{
			    ll i= 0;
				for(; i <= da; i++)
				{
					s= b[db] + a[i];
					sp= binariSearch(s, 0l, dc-i-1);
					if( sp <= x+1 )	c[dc++]= s;
					else			break;
				}
                sort(c, c+dc);
			}
		}
		else break;
	}
	fori(x)		printf("%ld\n",c[i]);
}

