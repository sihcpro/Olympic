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

ll a[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("test.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	cin >> n >> s1;
	
	
	for0(i, n){
		cin >> a[i];
//		cout << sp << " ";
	}
	
	ll bg= 0, ed= n-1, ma;
	if( n % 2 == 0 )
	{
		for0(i, n/2-1){
			if( ma > a[i+n/2+1] - a[i] || i == 0 ){
				ma = a[i+n/2+1] - a[i];
				x= i;
//				cout << ma << " ";
			}
		}
		for(int i= x+1; i < x+n/2+1; i++){
			
		}
	}

	return 0;
}









