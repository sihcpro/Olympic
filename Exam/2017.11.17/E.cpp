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
//	freopen("test.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	cin >> s1;

	map<string, int> m;
	for(int i= 0; i < s1.length(); i++){
		string si;
		si= s1[i];
		for(int j= 1; j < min( 10, (int)(s1.length() - i) ); j++){
			si+= s1[i+j];
			if( m.find(si) == m.end() )
				m[si]= 0;
			else
				m[si]= 1;
		}
	}
	
	for (std::map<string,int>::iterator it=m.begin(); it!=m.end(); ++it){
		if( it->second > 0 )
			it->second--;
			for(int i= 0; i < s1.length(); i++)
			{
				string si= it->first;
				bool kt= true;
				for(int j=0; j < si.length() && kt; j++){
					if( si[j] != s1[i+j] )	kt= false;
				}
				if( kt ){
					i+= si.length()-1;
					m[si]++;
				}
			}
		
	}

	n= s1.length();
//	cout << n << endl;
	for (std::map<string,int>::iterator it=m.begin(); it!=m.end(); ++it){
//		std::cout << it->first << " => " << it->second << '\n';
		if( it->second > 1 && n > ( s1.length() - (it->second-1)*( it->first.length() ) + it->second ) ){
			n= s1.length() - (it->second-1)*( it->first.length() ) + it->second;
//			std::cout << "this = " << n << endl;
		}
	}

	cout << n << endl;

	return 0;
}









