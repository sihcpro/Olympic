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

typedef pair<ll, pair<ll, ll> > cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;

ll n, m, sp, mid, top, bot, test, d, s, x, y;
string s1, s2;

int par[105];

int root(int v) {
    return ( par[v] < 0 ) ? v : (par[v] = root(par[v]));
}

void merge(int x, int y) {
    if ( (x = root(x)) == (y = root(y)) ){
        return ;
    }
    if ( x != 0 && y == 0 ) {
        swap(x, y);
    }
    par[y] = x;
}

int main(){
//	freopen("test.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	cin >> n >> m;

	int a[n+5], c[n+5];
	a[0]= 0;
	map< string , int > ma;
	ma["English"]= 0;

    par[0]= -1;
	for1(i, n){
		cin >> s1;
		ma[s1]= i;
		par[i]= -1;
		a[i]= 0;
		c[i]= 0;
	}

	pqmin hm[2];
	vector< pair<ll,ll> > v;

	for0(i, m){
		cin >> s1 >> s2 >> s;

		if( ma[ s1 ] == 0 ){
			v.push_back( make_pair( ma[s2], s ) );
			merge( ma[s2], 0);
		}
		else if( ma[ s2 ] == 0 ){
			v.push_back( make_pair( ma[s1], s ) );
			merge( ma[s1], 0);
		}
		else{
			cap mh;
			mh.first= s;
			mh.second= make_pair( ma[ s1 ], ma[ s2 ] );
			hm[0].push( mh );
		}
	}

	ll b, we;
	for(int i= 0; i < v.size(); i++){
		b= v[i].first;
		we= v[i].second;

		if( a[ b ] > we || a[b] == 0 ){
			a[ b ]= we;
		}
	}

	cap sp;
	ll w, b1, b2, t= 0, r1, r2;
	bool change= true;
	int i= 0;
	d= 2;
	while( change ){
		change = false;
		while( !hm[i].empty() ){
			sp= hm[i].top();
			hm[i].pop();

			w= sp.first;
			b1= sp.second.first;
			b2= sp.second.second;
			r1= root(b1);
			r2= root(b2);
			if( r1 == 0 && r2 == 0 ) continue;
			if( r1 != 0 && r2 != 0 ){
				hm[1-i].push( sp );
				continue;
			}
			change= true;
			if( c[b1] >= d || c[b2] >= d ){
				hm[1-i].push( sp );
				continue;
			}
			t+= w;
			merge( root(b1), root(b2) );
			if( r1 == 0 )
                c[b2]= d;
            else
                c[b1]= d;
		}
		d++;
		i= 1-i;
	}

	bool kt= true;
	s= 0;
	for1(i, n){
		if( root( i ) != 0 )	kt= false;
		s+= a[i];
	}

	if( kt )
		cout << s + t << endl;
	else
		cout << "Impossible\n";

	return 0;
}









