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

ll n, m, sp, mid, top, bot, test, d, s, x, y;
string s1, s2;

int main(){
	cin >> n >> m;
	
	bool a[n+5];
	for1( i, n+1)	a[i]= false;
	
	for0( i, m){
		cin >> x >> y;
		for(; x < y; x++){
			a[x]= true;
		}
	}
	
	d= 0;
	for1( i, n+1){
		if( a[i] ) 
			d+= 3;
		else
			d++;
	}
	
	cout << d << endl;
	
	return 0;
}








