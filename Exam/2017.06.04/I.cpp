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
#include <set>

using namespace std;

#define mod 1000000007ll
#define fori(n) for(ll i= 0; i < n; i++)
#define forj(n) for(ll j= 0; j < n; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;
typedef priority_queue<ll> pqmax;
typedef priority_queue<long, vector<long>, greater<long> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y, z;
ll n= 0, k= 0, s, d;
ll test;

string s1, s2;
ll tdx, txv, t0, t1, t2, t3;

void check()
{
	ll d1= min(x, y);
	ll d2= min(y, z);
	t1= ( d1 > 0 )?tdx + t:0;
	t2= ( d2 > 0 )?txv + t:0;
	
	ll maxT= max( t1, t2 );
	if( t1 == 0 && t2 == 0 )	return ;
	
	if( maxT <= 2*t )
	if( t1 > t2 )
	{
		s+= t1*d1;
		x-= d1;
		y-= d1;
	}
	else if( t1 < t2 )
	{
		s+= t2*d2;
		y-= d2;
		z-= d2;
	}
	else
	{
		if( d1 > d2 )
		{
			s+= t1*d1;
			x-= d1;
			y-= d1;
		}
		else
		{
			s+= t2*d2;
			y-= d2;
			z-= d2;
		}
	}
	
	check();
}

int main()
{
	cin >> test;
	while( test-- )
	{
		cin >> x >> y >> z;
		cin >> tdx >> txv >> t3 >> t;
		
		t3= ( x > 0 && y > 0 && z > 0 )?t3:0;
		t0= ( x > 0 && y > 0 && z > 0 )?(3*t):0;
		t1= ( x > 0 && y > 0 )?tdx + t:0;
		t2= ( y > 0 && z > 0 )?txv + t:0;
		
		ll maxT= max( max( t0, t1), max( t2, t3) );
		s= 0;
		
		if( t3 == maxT )
		{
			sp= min( min(x, y), z);
			s= t3*sp;
			x-= sp;
			y-= sp;
			z-= sp;
			check();
		}
		else if( maxT != 0 )
		{
			check();
		}
		else
		{
			s= (x + y + z)*t;
		}
		
		cout << s << endl;
	}
	
}

