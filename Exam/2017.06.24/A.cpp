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

string s1, s2;

bool a[205][205];

void change( char des, ll& x, ll& y)
{
	switch( des )
	{
		case 'U':	y++;	break;
		case 'D':	y--;	break;
		case 'L':	x--;	break;
		case 'R':	x++;	break;
	}
}

int main()
{
	cin >> x >> y;
	cin >> s1;
	
	ll X= 0ll, Y= 0ll;
//	a[X][Y]= true;
	fori(s1.length())
	{
		change( s1[i], X, Y);
//		a[X][Y]= true;
	}
	ll lengX= X;
	ll lengY= Y;
	
//	cout << X << "  " << Y << endl;
//	cout << lengX << "  " << lengY << endl;
	
	X= 0ll, Y= 0ll;
	if( x == 0 && y == 0 )
	{
		cout << "YES";
		return 0;
	}
	if( lengX == 0 )
	{
		if( lengY == 0 )
		{
			fori(s1.length())
			{
				if( x == X && y == Y )
				{
//					cout << X - 100ll << "  " << Y - 100ll << endl;
					cout << "YES";
					return 0;
				}
				change( s1[i], X, Y);		
			}
		}
		else
		{
			fori(s1.length())
			{
				if( x == X && ( y - Y ) % lengY == 0 && ( y - Y ) / lengY >= 0 )
				{
//					cout << X - 100ll << "  " << Y - 100ll << endl;
					cout << "YES";
					return 0;
				}
				change( s1[i], X, Y);		
			}
		}
	}
	else
	{
		if( lengY == 0 )
		{
			fori(s1.length())
			{
				if( ( x - X ) % lengX == 0 && y == Y && ( x - Y ) / lengX >= 0)
				{
//					cout << X - 100ll << "  " << Y - 100ll << endl;
					cout << "YES";
					return 0;
				}
				change( s1[i], X, Y);		
			}
		}
		else
		{
			fori(s1.length())
			{
				if( ( x - X ) % lengX == 0 && ( y - Y ) % lengY == 0 && ( x - X ) / lengX == ( y - Y ) / lengY && ( x - X ) / lengX >= 0 )
				{
//					cout << X - 100ll << "  " << Y - 100ll << endl;
					cout << "YES";
					return 0;
				}
				change( s1[i], X, Y);		
			}
		}
	}
	cout << "NO";
}








