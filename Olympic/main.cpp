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

ll junger= 0, mid= 0, top= 0, bot= 0, result= 0, sum= 0, s= 0, t= 0, d= 0, l= 0, sp= 0, k= 0, x, y, n, m, test, r, cnt;
bool kt= false, t1= false, t2= false;
string s1, s2;

struct fact{
	int fact;
	int x, y;
};

bool compare(fact a, fact b) {
	if (a.x == b.x) {
		return a.y < b.y;
	} else {
		return a.x < b.x;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("test.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	while( cin >> n >> m ){
		fact f[m];
		rep(0, i, m) {
			cin >> f[i].fact >> f[i].x >> f[i].y;
			f[i].x--;
			f[i].y--;
		}

		sort(f, f + m, compare);

		int b[1001] = {0};
		int fact_1 = 0;
		kt = true;
		rep(0, i , m) {
			if(f[i].fact == 1) {
				rep(f[i].x + 1, j, min(f[i].y + 1, (int)n)) {
					b[j] = 1;
				}
			}
		}
		rep(0, i , m) {
			if(f[i].fact == 0) {
				bool kt2 = false;
				rep(f[i].x + 1, j, min(f[i].y + 1, (int)n)) {
					if(b[j] == 0) {
						b[j] = -1;
						kt2 = true;
						break;
					} else if (b[j] == -1) {
						kt2 = true;
						break;
					}
				}
				if (!kt2) {
					cout << "NO\n";
					kt=false;
					break;
				}
			}
			if (!kt) break;
		}
		if (!kt) continue;

		int init = 1001;
		int a[1001] = {0};
		int j = 0;
		rep(0, i, n) {
			init += b[i];
			a[i] = init;
		}

		cout << "YES\n";
		// rep(0, i, n) {
		// 	cout << b[i] << " ";
		// }
		// cout << endl;
		rep(0, i, n) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
