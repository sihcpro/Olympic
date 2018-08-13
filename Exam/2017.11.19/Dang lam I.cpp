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

ll a[100000];
int da= 0;
void makeA(){
	ll i3= 1;
	for(int i= 1; i3 <= 44777444; i++, i3= i*i*i){
		a[da++]= i3;
	}
//	for(int i= 0; i < da; i++)
//		cout << a[i] << endl;
}

ll binariSearch(ll x, ll bot, ll top)
{
    ll mid= (top + bot)/2;
	if( x == a[mid] )			return mid;
	else if( bot == top )		return mid;
	else if( x < a[mid+1] )	    return binariSearch(x, bot, mid);
	else						return binariSearch(x, mid+1, top);
}

const ll MAX= 1800000;
int b[MAX+5], c[MAX+5], db[MAX+5];
void makeB(){
	b[0]= 0;
	for(int i= 1; i < MAX; i++){
		sp= binariSearch( i, 0, da-1);
//		cout << i << " = " << a[sp] << endl;
		for(int j= sp; j >= 0 && ( j == 0 || db[i] == 0 || a[j]*db[i] > i ); j--){
			sp= a[j];
			if( b[i] == 0 || 1 + db[i-sp] < db[i] ){
				b[i]= sp;
				c[i]= j;
				db[i]= 1 + db[i-sp];
			}
		}
	}

//	for(int i= 1; i < 44; i++)
//		cout << i << "  " << db[i] << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
//	freopen("test.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	makeA();
	makeB();

	cin >> n;

	if( n < MAX ){
		cout << db[n] << endl;
		while( n != 0 ){
			cout << c[n]+1;
			n-= b[n];
			if( n > 0 )
			cout << " ";
		}
		cout << endl;
	}
	else{
		sp= binariSearch( n, 0, da-1);
		int d= 0, e= 0, f= 0, num= 1, nu;
		for(int j= sp; j >= 0 &&( n-a[j] <= MAX )&& ( j == 0 || d == 0 || mid > n ); j--){
			sp= a[j];
			if( e == 0 || num + db[n-sp] < d ){
				e= sp;
				f= j;
				d= 1 + db[n-sp];
				nu= num;
			}
			while( n-a[j]*num > MAX ){
				num++;
			}
			mid= a[j-1]*( db[j-1] + num - 1);
		}
        cout << d << endl;
//        cout << n << endl;
		for(int i= 0; i < nu; i++){
		    n-= e;
		    cout << f+1;
			if( n > 0 )
			cout << " ";
		}
		while( n != 0 ){
			cout << c[n]+1;
			n-= b[n];
			if( n > 0 )
			cout << " ";
		}
		cout << endl;
	}

	return 0;
}









