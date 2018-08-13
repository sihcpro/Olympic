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

long long Flowers( long bg, long ed, long i, long j , long A[], long Q)
{
	long long flowers= 0;
	while( Q )
	{
		long left, right;
		long Max= 0, xMax;
		for(int x= i; x <= j; x++)
		{
			if( x == i ) 	left= bg;
			else			left= A[x-1];
			if( x == j )	right= ed;
			else			right= A[x+1];
			if( right - left > Max || x == i )
			{
				Max= right - left;
				xMax= x;
			}
		}
		if( xMax == i )
		{
            flowers+= ed - bg;
            bg= A[i]+1;
            i++;
		}
		else if( xMax == j )
        {
            flowers+= ed - bg;
            ed= A[j]-1;
            j--;
        }
        else
        {
            flowers+= ed - bg;
            flowers+=Flowers( bg, A[xMax]-1, i, xMax - 1, A, xMax - i ) + Flowers( A[xMax] + 1, ed, xMax + 1, j, A, j - xMax );
            return flowers;
		}
		Q--;
	}
	return flowers;
}

main()
{
	long P, Q;
	cin >> P >> Q;
	long A[105];
	for(int i= 0; i < Q; i++)
	{
		cin >> A[i];
	}
	for(int i= 0; i < Q-1; i++)
	{
		for(int j= i+1; j < Q; j++)
		{
			if( A[i] > A[j] )
			{
				long tg= A[i];
				A[i]= A[j];
				A[j]= tg;
			}
		}
	}

	long bg=1, ed= P, i= 0, j= Q-1;
	long long flowers= Flowers( bg, ed, i, j, A, Q);

	cout << flowers;
}















