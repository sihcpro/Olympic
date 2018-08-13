#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define mod 1000000007ll
#define for0(i, num) for(ll i= 0; i < num; i++)
#define for1(i, num) for(ll i= 1; i <= num; i++)
#define fordown(num) for(ll i= num-1; i >= 0; i--)
#define in(n) scanf("%lld", &n)
#define out(n) printf("%lld\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;

typedef pair<ll, pair<ll, ll> > cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;

ll n, m, sp, mid, top, bot, test, d, s, x, y;
string s1, s2;

int a[2][1000000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
//	freopen("test.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int k;
	cin >> k >> d;
	
	cin >> s1;
	n= s1.length();
	for0(i, n)
		a[0][i]= s1[i]-'0';
	
//	for0(i, n)
//		cout << a[0][i];
//	cout << "\n";
	
	int j= 0;
	while( k-- ){
		s= 0;
		for0(i, n/2){
			m= a[j][2*i];
			sp= a[j][2*i+1];
			for0(l, m){
				a[1-j][s++]= sp;
			}
		}
		j= 1-j;
		n= s;
//		for0(i, n)
//			cout << a[j][i];
//		cout << endl;
	}
	cout << a[j][d] << endl;

	return 0;
}









