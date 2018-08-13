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

long nt[1000000];
bool checkNt(ll x)
{
	long kt= sqrt(x);
    for(long i= 0; nt[i] <= kt; i++)
        if( x % nt[i] == 0 )	return false;
	return true;
}

long maxNt= 1;
void makeNt()
{
    nt[0]= 2;
    for(long i= 3; i < 1000500; i+= 2)
        if( checkNt(i) )    nt[maxNt++]= i;
}

int main()
{
	makeNt();
	
	ll k;
	cin >> test;
	while( test-- )
	{
		cin >> n >> k;
		
		if( n < 2*k )
		{
			cout << "No";
		}
		else
		{
			if( k == 1 )
			{
				if( checkNt(n) )
					cout << "Yes";
				else
					cout << "No";
			}
			else if( k == 2 )
			{
				if( n%2 == 0 || checkNt(n-2) )
					cout << "Yes";
				else
					cout << "No";
			}
			else
				cout << "Yes";
		}
		cout << endl;
	}
	
	return 0;
}








