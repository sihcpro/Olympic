#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll
#define fori(num) for(ll i= 0; i < num; i++)
#define forj(num) for(ll j= 0; j < num; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y, d;
ll n= 0, k= 0, s;
ll test;

string s1, s2;

long a[100], i= 0;
string T= "aaabaaaaaabaaaaaaab";
string S= "aab";

void xuatA()
{
    for(long j= 0; j < m; j++)  cout << a[j] << " ";
    cout << endl;
}

ll find(string S, string T)
{
//    cin >> S;
    a[0]= 0;
    m= S.length();
    cout << T << endl;
    cout << S << endl;
    for(long i= 1; i < m; i++)
    {
        k= a[i-1];
        while( k > 0 && S[k] != S[i] )
            k= a[k-1];
        if( S[k] != S[i] )
            a[i]= 0;
        else
            a[i]= k+1;
//        xuatA();
    }

    k= 0;
    n= T.length();
    d= 0;
    fori(n)
    {
    	if( T[i] == S[k] )
    	{
    		k++;
    		if( k == m )
			{
				return i+1;
			}
		}
		else
		{
	        while( k > 0 && S[k] == T[i+1] )
	            k= a[k-1];
		}
	}

	return -1;
}

int main()
{
	cin >> s1;
	cin >> s2;

	string sa= s1;
	while( sa.length() < 2*s2.length() )
	{
		sa+= sa;
	}

	ll kq= find( s2, sa);

//	cout << kq << endl;

	if( kq == -1 )
        cout << -1;
	else
	{
	    sp= (kq-1ll);
//	    cout << sp << endl;
//	    cout << s1.length() << endl;
		cout << sp/(s1.length())+1ll;
	}

}
