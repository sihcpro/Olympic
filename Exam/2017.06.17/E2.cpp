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

ll s1, s2;

ll a[100005];
ll b[100005];

int main()
{
	cin >> n;

	n--;
	ll maxS1= 0, minS1= 0;
	ll maxS2= 0, minS2= 0;
	s1= 1;
	s2= 0;

	bool kt= false;
	b[0]= 0;
	ll first= 0, last= 0;
	for(ll i= 2; i <= n+1; i++)
	{
		in(a[i]);
		if( first == 0 )    first= a[i];
		if( a[i]  != 0 )    last = a[i];

		if( kt && a[i] == 1 )
		{
			ll j= i-1;
			b[i]= 8;
			b[j]= 9;
			while( a[j] == -1 )
			{
				b[j-1]= b[j]+a[j];
				j--;
			}
			kt= false;
		}
		else
		{
            if( a[i] == -1 ) kt= true;
			b[i]= b[i-1] - a[i];
		}
	}
	for(ll i= 1; i <= n+1 ; i++)	printf("%lld", b[i]);	cout << endl;

	if( last == -1 || last == 0 )
    {
        cout << "last" << endl;
        ll j= n+1;
        b[j]= 9;
        while( a[j] == -1 )
        {
            b[j-1]= b[j]+a[j];
            j--;
            for(ll i= 1; i <= n+1 ; i++)	printf("%lld", b[i]);	cout << endl;
        }
        if( a[j] > 0 )      b[j]= min( b[j], b[j-1]-a[j] );
    }


    if( first == 1 )
    {
        cout << "first" << endl;
        ll j= 1;
        b[j]= 9;
        while( a[j+1] == 1 )
        {
            b[j+1]= b[j]-a[j+1];
            j++;
            for(ll i= 1; i <= n+1 ; i++)	printf("%lld", b[i]);	cout << endl;
        }
        if( a[j+1] < 0 )      b[j]= min( b[j], b[j+1]+a[j+1] );
    }

	for(ll i= 2; i <= n+1 && kt; i++)
    {
        if( a[i] == 0 )
        {
            for(ll i= 1; i <= n+1 ; i++)	printf("%lld", b[i]);	cout << endl;
            x= i+1;
            while( a[x] == 0 )  x++;
            cout << b[i-1] << "  " << b[x-1] << endl;
            s= min( b[i-1], b[x-1] );
            for(ll j= i-1; j < x; j++)
                b[j]= s;
            i= x;
        }
    }

    kt= true;
    if( b[1] <= 0 ) kt= false;

    for(ll i= 1; i <= n+1 ; i++)	printf("%lld", b[i]);   cout << endl;
	for(ll i= 2; i <= n+1 && kt; i++)	if( b[i] < 0 || b[i] > 9 ) kt= false;

	if( kt )
    {
        for(ll i= 1; i <= n+1 ; i++)	printf("%lld", b[i]);
    }
    else
    {
        cout << -1;
    }
}



