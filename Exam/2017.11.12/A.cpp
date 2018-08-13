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

typedef pair<ll, long> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;

ll n, m, sp, mid, top, bot, test, d, s;
string s1, s2;

ll a[30], b[30], c[30];

int main(){
	cin >> n >> m;
	
	ll d0, d1, sa, sb, m0[30], m1[30];
	d0= d1= 0;
	for1(i, n){
		in( a[i] );
		if( a[i] == 0 )
			m0[d0++]= i;
		else
			m1[d1++]= i;
	}
	sa= sb= 0;
	for1(i, m){
		in( b[i] );
		if( i % 2 )
			sa+= b[i];
		else
			sb+= b[i];
	}
	
//	cout << d0 << "  " << d1 << endl;
//	cout << sa << "  " << sb << endl;
	
	ll j;
	if( sa != sb ){
		if( sa == d0 )
			j= 0;
		else
			j= 1;
		d= 1;
		for1(i, m){
			for0(k, b[i])
				c[d++]= j;
			j= 1- j;
		}
//		for1(i, n)
//			cout << c[i] << " ";
//		cout << endl;
		j= 0;
		s= 0;
		for1(i, n){
			if( c[i] == 1 )
				s+= abs( m1[j++] - i );
		}
		cout << s << endl;
	}
	else{
		j= 0;
		d= 1;
		for1(i, m){
			for0(k, b[i])
				c[d++]= j;
			j= 1- j;
		}
//		for1(i, n)
//			cout << c[i] << " ";
//		cout << endl;
		j= 0;
		s= 0;
		for1(i, n){
			if( c[i] == 1 )
				s+= abs( m1[j++] - i );
		}
		ll ss= s;
/* ------------------------------------------ */

		j= 1;
		d= 1;
		for1(i, m){
			for0(k, b[i])
				c[d++]= j;
			j= 1- j;
		}
//		for1(i, n)
//			cout << c[i] << " ";
//		cout << endl;
		j= 0;
		s= 0;
		for1(i, n){
			if( c[i] == 1 )
				s+= abs( m1[j++] - i );
		}
		
		cout << min( s, ss);
	}
	
	return 0;
}








