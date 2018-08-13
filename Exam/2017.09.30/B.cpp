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

int main()
{
	cin >> n;
	cin >> s1;
	
	bot = 0;
	top = n-1;
	
	s2 = "";
	for0(i, n)
	{
		if ( s1[bot] < s1[top] ) 
			s2+= s1[bot], bot++;
		else if( s1[bot] > s1[top] )
			s2+= s1[top], top--;
		else
		{
			int i= 1;
			for(; i < (top-bot+1)/2 && s1[bot+i] == s1[top-i]; i++);
//			cout << endl << s1[bot] << i << s1[top] << endl;
			if ( s1[bot+i] < s1[top-i] )
				s2+= s1[bot], bot++;
			else
				s2+= s1[top], top--;
		}
	}
	cout << s2 << endl;

	return 0;
}








