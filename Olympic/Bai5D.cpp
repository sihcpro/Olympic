#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <utility>

//#include "segment_tree.h"
//#include "fenwick_tree.h"
//#include "union_find.h"
//#include "geometry.h"
using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define DOW(i,a,b) for(int i = (a); i >= (b); i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define FORI(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define RESET(c,val) memset(c,val,sizeof(c))

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

#define sz(a) int(a.size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

// bitmask
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

// other manipulation
#define modulo(S, N) ((S) & (N - 1)) // return S % N, where N = 2^k
#define isPowerOfTwo(S) (!(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) & (S - 1))


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

/*---------------------------*/

void show(vector<long> a, vector<long> b)
{
	for(int i= 0; i < a.size(); i++)
    {
        cout << a[i] << "  " << b[i] << endl;
    }
}

main()
{
	int n, i, j;
	long long T= 0;
	vector<long> a, b;
	long tg, Cin;

	cin >> n;
	for( i= 0; i < n; i++)
	{
		cin >> Cin;
		a.push_back(Cin);
	}
	for( i= 0; i < n; i++)
	{
		cin >> Cin;
		b.push_back(Cin);
	}

	for( i= 0; i < n-1; i++)
	{
		for( j= i; j < n; j++)
		{
			if( a[i] > a[j] )
			{
				tg  = a[i];
				a[i]= a[j];
				a[j]= tg;
			}
		}
	}
	for( i= 0; i < n-1; i++)
	{
		for( j= i; j < n; j++)
		{
			if( b[i] > b[j] )
			{
				tg  = b[i];
				b[i]= b[j];
				b[j]= tg;
			}
		}
	}

//    show(a, b);

	for(; b[n-1] > 0 && a[0] < 0 && n > 0;)
	{
		T+= a[0] * b[n-1];
		a.erase( a.begin() );
		b.erase( b.end() - 1 );
		n--;
	}
//	show(a, b);
	for( ; a[n-1] > 0 && b[0] < 0 && n > 0;)
	{
		T+= b[0] * a[n-1];
		b.erase( b.begin() );
		a.erase( a.end() - 1 );
		n--;
	}
//    show(a, b);
	for(; n > 0;)
	{
		T+= a[n-1] * b[0];
		b.erase( b.begin() );
		a.erase( a.end() - 1 );
		n--;
	}

	cout << T << endl;
}















