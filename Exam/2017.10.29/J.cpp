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

ll n, m, sp, mid, top, bot;
string s1, s2;

int a[1000005], b[1000005];

int main()
{
	cin >> s1 >> s2;
	
	for(long i= 0; i < s2.length(); i++)
	{
		b[i] = s2[i] - '0';
		if( i < ( s2.length() - s1.length() ) )
			a[i] = 0;
		else
			a[i] = s1[ i - ( s2.length() - s1.length() ) ] - '0';
	}

//	for(long i= 0; i < s2.length(); i++)
//		cout << (char)( a[i] + '0' );
//	cout << endl;
//	
//	for(long i= 0; i < s2.length(); i++)
//		cout << (char)( b[i] + '0' );
//	cout << endl;

	long d= 0;
	bool kt= false;
	for(long i= 0; i < s2.length(); i++)
	{
		if( b[i] != a[i] )
		{
			d++;
			if( b[i] > a[i] )
				kt= true;
		}
		else if( kt )
			d++;
	}
	
	cout << d << endl;
	
	return 0;
}









