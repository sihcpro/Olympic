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

int W[102][102];
int n, m;

void boiDen( int x, int i, int j)
{
    W[i][j]= x;
	if( i > 0 && j > 0 && W[i-1][j-1] > 0 && W[i-1][j-1] != x ) boiDen(x, i-1, j-1);		//	TB
	if(          j > 0 && W[i  ][j-1] > 0 && W[i  ][j-1] != x ) boiDen(x, i  , j-1);		//	T
	if( i < n && j > 0 && W[i+1][j-1] > 0 && W[i+1][j-1] != x ) boiDen(x, i+1, j-1);		//	TN
	if( i < n          && W[i+1][j  ] > 0 && W[i+1][j  ] != x ) boiDen(x, i+1, j  );		//	N
	if( i < n && j < m && W[i+1][j+1] > 0 && W[i+1][j+1] != x ) boiDen(x, i+1, j+1);		//	DN
	if(          j < m && W[i  ][j+1] > 0 && W[i  ][j+1] != x ) boiDen(x, i  , j+1);		//	D
	if( i > 0 && j < m && W[i-1][j+1] > 0 && W[i-1][j+1] != x ) boiDen(x, i-1, j+1);		//	DB
	if( i > 0          && W[i-1][j  ] > 0 && W[i-1][j  ] != x ) boiDen(x, i-1, j  );		//	B
}

main()
{
	cin >> n >> m;
	for(int i= 0; i < n; i++)
	{
		for(int j= 0; j < m; j++)
		{
			char c;
			cin >> c;
			if( c == 'W' ) 	W[i][j]= 1;
			else			W[i][j]= 0;
		}
	}
	/*
	for(int i= 0; i < n; i++)
	{
		for(int j= 0; j < m; j++)
		{
			cout << W[i][j];
		}
		cout << endl;
	}
	*/
    int count = 1;
	for(int i= 0; i < n; i++)
	{
		for(int j= 0; j < m; j++)
		{
			if ( W[i][j] == 1 )
			{
				boiDen(++count, i, j);
			}
		}
	}
    /*
	for(int i= 0; i < n; i++)
	{
		for(int j= 0; j < m; j++)
		{
			cout << W[i][j];
		}
		cout << endl;
	}
    */
    cout << count-1;
}














