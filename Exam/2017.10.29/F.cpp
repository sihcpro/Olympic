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

//ll n, m, sp, mid, top, bot;
//string s1, s2;

ll n, s, s2, d, m, sum;
int a[14];

int main(){
	long test;
	cin >> test;
    while(test--){
    	cin >> n;
    	s= 1,s2= 0;

    	d= 0, m= n;
    	sum= 0;
    	while( m != 0 ){
    		a[d]= m%10;
//    		s2+= m%10;
//    		if( m%10 == 1 ) sum= -1;
    		d++;
    		m/= 10;
		}
		if( d == 1 )	sum= -1;

		for(int i= 0; i < d-1; i++){
			sum+= 9 + 10*i;
			s*= 10;
		}
//		cout << sum << " " << s2 << "   ";

//		cout << "[";
		for(int i= 0; i < d-1; i++){
//			cout << s2 << ";";
			if( i == 0 )
				s2+= a[i];
			else if ( a[i] != 0 )
				s2+= a[i]+1;
		}
//		cout << "]  " << sum << "  ";

		if( s2 == 0 && d > 1 )
		{
//			cout << "->";
			if( a[d-1] == 2 ){
				s2+= 10 + (d-2)*10;
			}
			else if( a[d-1] != 1 ){
				s2+= a[d-1];
				s2+= 9 + (d-2)*10;
			}
		}
		else{
			if( a[d-1] != 1 )
				s2+= a[d-1];
		}

		bool thdb= false;
		
		if( a[d-1] != 1 )
			for(int i=1; i < d-1; i++)
				if( a[i] == 1 ) thdb= true;

//		cout << "=\t ";
		cout << max( 0ll, sum + s2 - thdb ) << endl;

	}
}








