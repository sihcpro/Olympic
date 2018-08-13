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


ll t, m, sp, junger, mid, top, bot, x, y;
ll n= 0, k= 0, s;
ll test;

string s1, s2;

ll a[100005];
ll b[100005];

int main()
{
	cin >> n >> x >> y;

	fori(n)
	{
		cin >> mid >> sp;
		a[i]= mid-sp;
		b[i]= mid+sp;
	}

	sort(a, a+n);
	sort(b, b+n);

	ll now= min( a[0], x );
	m= 0;					//	dem so luong linh tai vi tri now
	top= 0;
	bot= 0;
	s= 0;
	while( now < x )
	{
		if( a[top] <= b[bot] && top < n )	//	now gan cho nao
		{
			if( m == 0 )		//	Neu nay gio di khong co ai bao ve
			{
                if( a[top] <= y ) ;
                else
                    break;
			}
			if( a[top] < x )
            {
                m++;
                now= a[top++];
            }
            else
            {
                now= x;
                break;
            }
		}
		else if( bot < n )
		{
			if( b[bot] < x )
            {
                m--;
                now= b[bot++];
            }
            else
            {
                now= x;
                break;
            }
		}
		else break;
	}
	while( now <= y )
	{
		if( a[top] <= b[bot] && top < n )	//	now gan cho nao
		{
			if( m == 0 )		//	Neu nay gio di khong co ai bao ve
			{
                if( a[top] <= y )
                    s+= a[top] - now;
                else
                    break;
			}
			m++;
			now= a[top++];
		}
		else if( bot < n )
		{
			m--;
			now= b[bot++];
		}
		else break;
	}
	if( m == 0 && now < y )
    {
        if( now >= x )      s+= y - now;
        else                s+= y - x;
    }

	cout << s;
}

