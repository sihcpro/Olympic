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

int A[50][50];
int Count= -1;

void taoMang(int a, int b)
{
	// trai -> phai
	for(int i= a; i < b; i++ )
	{
		A[a][i]= ++Count;
	}
	// tren xuong
	for(int i= a; i < b; i++ )
	{
		A[i][b]= ++Count;
	}
	// phai <- trai
	for(int i= b; i > a; i-- )
	{
		A[b][i]= ++Count;
	}
	// duoi len
	for(int i= b; i > a; i-- )
	{
		A[i][a]= ++Count;
	}
}

int main()
{
	int n;

	cin >> n;
	for(int i= 0; i < (n+1)/2; i++)
	{
		if( i == ( n - 1 )/2 && n % 2 == 1 )
		{
            A[( n - 1 )/2][( n - 1 )/2]= ++Count;
		}
		else
        {
            taoMang( i, n-i-1);
        }
	}

	for(int i= 1; i <= n; i++)
	{
		for(int j= 1; j <= n; j++)
		{
			cout << A[i-1][j-1];
			if (j < n) cout << " ";
		}
		if (i < n) cout << endl;
	}

}














