#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll
#define for0(i, num) for(ll i= 0; i < num; i++)
#define for1(i, num) for(ll i= 1; i <= num; i++)
#define fordown(num) for(ll i= num-1; i >= 0; i--)
#define in(n) scanf("%lld", &n)
#define out(n) printf("%lld\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y, d, test;
ll n= 0, k= 0, s;
string s1, s2;

queue<char> a;

int main()
{
	cin >> s1;
	
	bool kt= true;
	
	for(int i = 0; i < s1.length(); i++)
	{
		if( s1[i] == '/' )
		{
			if( kt )
			{
				a.push(s1[i]);
				kt = false;
			}
		}
		else
		{
			kt= true;
			a.push(s1[i]);
		}
	}
	
	while( !a.empty() )
	{
		cout << a.front();
		a.pop();
		if( a.size() == 1 )
		{
			if( a.front() != '/' )
			{
				cout << a.front();
				a.pop();
			}
			else
				a.pop();
		}
	}
	

	return 0;
}








