#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define PI 3.14159265

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

#define siz(x) (int)(x).size()
#define Y second
#define X first
#define IN insert
#define PB push_back
#define P pop_back
#define PU push
#define PO pop
#define F find
#define ED end()
#define MP( a, b) make_pair( a, b )

#define MOD 1000000007ll
#define rep( bg, i, num ) for(ll (i)= (bg); (i) < (num); ++(i))
#define repd( num, i, ed ) for(ll (i)= (num)-1; (i) >= ed; --(i))
#define repkt( bg, i, num, kt ) for(ll (i)= (bg); (i) < (num) && (kt); ++(i))
#define repchar( i ) for(char (i)= 48; (i) <= 122; (i)++)
#define in(n) scanf("%lld", &n)
#define out(n) printf("%lld\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0, j= sizeof(a)/sizeof(a[0]); i < j; ++i) a[i]= n;

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;

ll junger= 0, mid= 0, top= 0, bot= 0, result= 0, sum= 0, s= 0, t= 0, d= 0, l= 0, sp= 0, k= 0, x, y, n, m, test, r;
bool kt= false, t1= false, t2= false;
string s1, s2;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("test.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	while( cin >> n ){
		int a[2][n+5];
		rep(0,i,2) {
			rep(0,j,n) {
				cin >> a[i][j];
			}
		}

		ll b[2][n+5], c[2][n+5], sp1[2], sp2[2];
		setA(b[0], 0)
		setA(b[1], 0)
		setA(c[0], 0)
		setA(c[1], 0)

		repd(n,i,0) {
			rep(0,j,2) {
				c[j][i] = c[j][i+1] + a[j][i];
			}
		}

		repd(n,i,0) {
			// b[0][i] = b[0][i+1] + (2*n)*a[0][i] - c[0][i+1];
			b[0][i] = b[0][i+1] + (2*n-1)*a[0][i] + (2*i)*a[1][i] - c[0][i+1] - c[1][i+1];
			b[1][i] = b[1][i+1] + (2*n-1)*a[1][i] + (2*i)*a[0][i] - c[1][i+1] - c[0][i+1];
			// cout << i << " " << (2*i+1) << " " << b[0][i] << " " << b[1][i] << endl;
		}
		// cout << "-----------------------------\n";

		int j= 0;
		ll maxS = b[1][0];
		sp= 0;
		rep(0,i,2*n) {
			if( i%2 == 1 )
				j= 1-j;
			else
				maxS = max(maxS, sp+b[1-j][i/2]);
			sp+= i*a[j][i/2];
			// cout << i/2 << " " << j << " = " << sp << " -> " << maxS << endl;
		}
		// cout << "-----------------------------\n";

		cout << maxS << endl;
	}

	return 0;
}
