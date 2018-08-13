#include <iostream>
#include <vector>
#include <stdio.h>

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
//typedef priority_queue<cap> pqmax;
//typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;

ll t, m, sp, junger, mid, top, bot, x, y, d, test;
ll n= 0, k= 0;
string s1, s2;

struct ple{
	vector<long> v;
};

long a[100005];
ple  b[400005];

vector<long> mergeSihc( vector<long>& v1, vector<long>& v2)
{
	long l1= v1.size();
	long l2= v2.size();
	vector<long> v;
	long i1= 0, i2= 0;
    if( l1 == 0 )
        return v2;
    else if( l2 == 0 )
        return v1;
	while( i1 < l1 || i2 < l2 )
	{
		if( i2 < l2 && v1[i1] < v2[i2] || i1 == l1 )
		{
			v.push_back(v2[i2]);
			i2++;
		}
		else
		{
			v.push_back(v1[i1]);
			i1++;
		}
	}
	return v;
}

vector<long> build(long id, long l, long r)
{
	if( l == r )
	{
		b[id].v.push_back(a[l]);
		return b[id].v;
	}

	long mid= (l+r)/2;

	vector<long> v1= build(id*2, l, mid);
	vector<long> v2= build(id*2+1, mid+1, r);
	b[id].v = mergeSihc( v1, v2 );
//	cout << endl << id << "    " << l << "->" << r << endl;
//	for0(i, b[id].v.size() )
//		cout << b[id].v[i] << " ";
	return b[id].v;
//	long *v1= build(id*2, l, mid);
//	vector<long> v2= build(id*2+1, mid+1, r);
//
//	merge( v1.begin(), v1.end(), v2.begin(), v2.end(), b[id].v);
}

vector<long> query(long id, long u, long v, long l, long r)
{
	if( v < l || r < u )
	{
		vector<long> vnull;
		return vnull;
	}
	if( u <= l && r <= v )
		return b[id].v;

	long mid = (l+r)/2;
	vector<long> v1= query(id*2, u, v, l, mid);
	vector<long> v2= query(id*2+1, u, v, mid+1, r);
	return mergeSihc( v1, v2 );
}

int main()
{
	cin >> n >> m;

	for1(i, n)
		scanf("%ld", &a[i] );

	build(1, 1, n);

	for0(i, m)
	{
		long x, y, d;
		scanf("%ld %ld %ld", &x, &y, &d);
//		vector<long> v = query( 1, x, y, 1, n);
//		for0(i, v.size() )
//			cout << v[i] << " ";
//		cout << endl;
		printf("%ld\n", query( 1, x, y, 1, n)[d-1]);
	}



	return 0;
}








