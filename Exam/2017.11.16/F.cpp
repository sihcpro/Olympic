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

struct node{
	int w, g;	// weigh, group

	node(){
	    w= g= 0;
	}
};

int main(){
//	freopen("test.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	cin >> n >> m;

	while( n != 0 && m != 0 ){
		ll numGrp= 0;
		vector< vector<int> > v;
		vector<int> vsp;
		v.push_back(vsp);

		node a[n+1];

		char c;
		int x, y, w;
		for0(i, m){
			scanf("\n");
			scanf("%c %d %d", &c, &x, &y);
			if( c == '!' ){
				scanf("%d", &w);
				if( a[x].g == 0 && a[y].g == 0 ){
					a[x].g = a[y].g = ++numGrp;
					vector<int> vv;
					vv.push_back(x);
					vv.push_back(y);
					v.push_back(vv);
					a[x].w = w;
					a[y].w = 0;
				}
				else if( a[x].g != 0 && a[y].g != 0 ){
					if( a[x].g == a[y].g )
						continue;
					if( v[ a[x].g ].size() < v[ a[y].g ].size() ){
						swap(x, y);
						w*= -1;
					}
					int gt= ( a[x].w - w ) - a[y].w, g= a[x].g, gy= a[y].g, tg;
					for0(j, v[ gy ].size() ){
					    tg= v[ gy ][j];
						a[tg].g = g;
						a[tg].w += gt;
                        v[g].push_back(tg);
					}
				}
				else{
					if( a[x].g == 0 ){
						swap(x, y);
						w*= -1;
					}
					a[y].g = a[x].g;
					a[y].w = a[x].w - w;
					v[ a[x].g ].push_back( y );
				}
			}
			else{
				if( a[x].g == a[y].g && a[x].g != 0 )
					printf( "%d\n", a[x].w - a[y].w);
				else
					printf( "UNKNOWN\n" );
			}
		}
		cin >> n >> m;
	}

	return 0;
}









