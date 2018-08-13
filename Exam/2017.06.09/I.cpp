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

ll b[100005];

int main()
{
	cin >> n >> s1;

	m= 0;
	ll db= 0;
	ll dA= 0;
	fori(n)
	{
        if( s1[i] == 'A' )
        {
            dA++;
            if( d != 0 )
            {
            	b[db++]= d;
            	d= 0;
			}
        }
        else
        {
            d++;
        }
	}
    if( d != 0 )
    {
        b[db++]= d;
        d= 0;
    }

//	cout << d << "  " << s << "  " << kt << "  " << dA << endl;

    if( dA % 2 == 0 )
    {
        cout << -1;
        return 0;
    }
    else
    {
    	x= 0;
    	fori(db)
            x^= b[i];

    	bool kt= false;
    	fori(db)
    	{
//    	    cout << (b[i]^x) << "   " << b[i] << endl;
			if( (b[i]^x) < b[i] )
			{
				kt= true;
				break;
			}
    	}

		if( kt )
			cout << "A";
		else
			cout << "B";
    }
}

