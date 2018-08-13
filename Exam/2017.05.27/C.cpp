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

typedef struct
{
	ll a, b, c, d;
} Mt;

Mt mtdv;

ll mu(ll soMu, ll so)
{
	if( soMu == 1 )	return so;
	else
	{
		ll num= mu(soMu/2, so);
		num= (num * num) % mod;
		if( soMu % 2 == 0)
			return num;
		else
			return ( num*so ) % mod;
	}
}

Mt nhanMt( Mt a, Mt b)
{
	Mt kq;
	kq.a= ( a.a*b.a + a.b*b.c ) % mod;
	kq.b= ( a.a*b.b + a.b*b.d ) % mod;
	kq.c= ( a.c*b.a + a.d*b.c ) % mod;
	kq.d= ( a.c*b.b + a.d*b.d ) % mod;
	return kq;
}

Mt muMt(ll i)
{
	if( i == 1 )	return mtdv;
	else
	{
		Mt kq= muMt(i/2);
		kq= nhanMt( kq, kq);
		if( i%2 == 0 )
			return kq;
		else
			return nhanMt( kq, mtdv);
	}
}

ll CSC(ll A, ll n)
{
	if( n == 0 )	return 1;
	if( n == 1 )	return A+1;
	
	mtdv.a= 1;
	mtdv.b= 0;
	mtdv.c= 1;
	mtdv.d= A;
	
	Mt mtKQ= muMt(n-1);
	ll kq= ( A*mtKQ.d + A*mtKQ.c + 1 ) % mod;
	return kq;
}

int main()
{	
	ll A, B, x;
	cin >> A >> B >> n >> x;

	

	sp= mu( n, A);

//	cout << B*CSC(A, n-1) << "  " << sp*x << endl;
//	if ( A == 1 )
//		s= ( B + sp*x) % mod;
//	else
	s= ( B*CSC( A, n-1 ) + sp*x ) % mod;
	
	cout << s;
}

