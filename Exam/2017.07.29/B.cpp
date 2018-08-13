#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll
#define fori(num) for(ll i= 0; i < num; i++)
#define forj(num) for(ll j= 0; j < num; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y, d;
ll n= 0, k= 0, s;
ll test;

struct node{
	int gt, maxT, maxB, maxL, maxR;
	
	node()
	{
		maxT= 0, maxB= 0, maxL= 0, maxR= 0;
	}
};

node a[105][105];

void checkTL(int i, int j)
{
	if( j > 1 )
		a[i][j].maxL= max( a[i][j-1].maxL, a[i][j-1].gt );
	else
		a[i][j].maxL= 0;
	
	if( i > 1 )
		a[i][j].maxT= max( a[i-1][j].maxT, a[i-1][j].gt );
	else
		a[i][j].maxT= 0;
}

void checkRB(int i, int j)
{
	if( j < y )
		a[i][j].maxR= max( a[i][j+1].maxR, a[i][j+1].gt );
	else
		a[i][j].maxR= 0;
	
	if( i < x )
		a[i][j].maxB= max( a[i+1][j].maxB, a[i+1][j].gt );
	else
		a[i][j].maxB= 0;
}

int main()
{
	cin >> x >> y;
	
	fori(x)
		forj(y)
		{
			cin >> a[i+1][j+1].gt;
			checkTL(i+1, j+1);
		}
	
	for(int i= x; i >= 1; i--)
		for(int j= y; j >= 1; j--)
		{
			checkRB(i, j);
		}
	
//	fori(x)
//	{
//		forj(y)
//			cout << a[i+1][j+1].maxL << " ";
//		cout << endl;
//	}
//
//	fori(x)
//	{
//		forj(y)
//			cout << a[i+1][j+1].maxT << " ";
//		cout << endl;
//	}
	
	s= 0;
	fori(x)
		forj(y)
		{
			s+= ( a[i+1][j+1].gt > a[i+1][j+1].maxL );
			s+= ( a[i+1][j+1].gt > a[i+1][j+1].maxR );
			s+= ( a[i+1][j+1].gt > a[i+1][j+1].maxT );
			s+= ( a[i+1][j+1].gt > a[i+1][j+1].maxB );
		}
		
	cout << s;

	return 0;
}








