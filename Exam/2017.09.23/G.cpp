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

typedef pair<ll, ll> cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y, d, test;
ll n= 0, k= 0, s;
string s1, s2;

vector<long> a;

int main()
{
	int b[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	d= 0;
	for(int i= 1; i < 9; i++)
	{
		for(int j= i+1; j < 10; j++)
		{
//			cout << b[i] << b[j] << "  ";
//				cout << (1ll<<1-1) << endl;
			for(int g= 1; g < 10; g++)
			{
				for(ll k= 1ll; k < (1ll<<g)-1;k++)
				{
					m= 0;
					sp= k;
					for(int l= 0; l < g; l++)
					{
						m*= 10ll;
						m+= ( sp&1 )?b[i]:b[j];
						sp/= 2;
					}
					a.push_back(m);
					d++;
				}
			}
		}
	}
	
		for(int j= 1; j < 10; j++)
		{
//			for(int g= 1; g < 10; g++)
//			{
				for(ll k= 1ll; k < (1ll<<9)-1;k++)
				{
					m= 0;
					sp= k;
					for(int l= 0; l < 9; l++)
					{
						m*= 10ll;
						m+= ( sp&1 )?b[0]:b[j];
						sp/= 2;
					}
					a.push_back(m);
					d++;
				}
//			}
		}
	
//	a.push_back(0);
	a.push_back(111111111);
	a.push_back(222222222);
	a.push_back(333333333);
	a.push_back(444444444);
	a.push_back(555555555);
	a.push_back(666666666);
	a.push_back(777777777);
	a.push_back(888888888);
	a.push_back(999999999);
	a.push_back(1000000000);
	a.push_back(1000000001);
	sort( a.begin(), a.end() );
//	cout << d << endl;
	
//	for(int i= 0; i < 500; i++)
//		cout <<  ":  " << a[i+38000] << endl;
	
	cin >> n;

	int i= 0;
	d= 0;
	
	while( a[i] <= n )
	{
		i++;
		d++;
	}
	
	cout << d;
	
	return 0;
}








