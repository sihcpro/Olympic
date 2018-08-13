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

int a[205][105], b[205];

int u[1005][1005];

int gcd(int a, int b)
{
	int temp;
	while(b>0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
void buildUCLN(){
	for(int i= 1; i <= 1000; i++)
		u[1][i]= u[i][1]= u[0][i]= u[i][0]= 1;
	for(int i= 2; i <= 1000; i++){
		u[i][i]= i;
		for(int j= i+1; j <= 1000; j++)
			u[i][j]= u[j][i]= gcd(i, j);
	}
}

int main(){
	freopen("test.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	buildUCLN();
	cin >> n;

	while( n > 0 ){
		for0(i, n)
			scanf("%d", &b[i]);
		for0(i, n)
			b[i+n]= b[i];

		ll bf, af;
		for0(i, 2*n){
			bf= ( i ==     0 ) ? b[2*n-1] : b[i-1];
			af= ( i == 2*n-1 ) ? b[0]     : b[i+1];
			a[1][i]= u[ bf ][ af ];
		}
		for(int i= 2; i <= n-2; i++){
			for(int j= 0; j <= 2*n-i; j++){
//				if( j == 0 || i+j == n-1 )
//					cost= 1;
//				else
//					cost= u[ b[j] ][ b[i+j] ];
				bf= ( j == 0     ) ? b[2*n-1] : b[j-1];
				af= ( i+j == 2*n ) ? b[0]     : b[i+j];
				a[i][j]= min( a[i-1][j] + u[ bf ][ af ], a[i-1][j+1] + u[ bf ][ af ] );
			}
		}

		ll mi;
		for0(j, n){
		    ll i= n-2;
            bf= ( j == 0     ) ? b[2*n-1] : b[j-1];
            af= ( i+j == 2*n ) ? b[0]     : b[i+j];
			if( j == 0 )
				mi= min( a[ n-2 ][ i ] + u[ bf ][ af ], a[ n-2 ][ i+1] + u[ bf ][ af ] );
			else
				mi= min( (ll)min( a[ n-2 ][ i ] + u[ bf ][ af ], a[ n-2 ][ i+1] + u[ bf ][ af ] ), mi );
		}

        if( n == 2 )
            cout << u[ b[0] ][ b[1] ] << endl;
        else
            cout << mi << endl;

		cin >> n;
	}

	return 0;
}









