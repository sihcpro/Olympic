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

long chia1SoThanhNhieuTong(int n, int m, int M)
{
	if( m == 2 ) return (long)n/m;
	if( n - m == 0 || n - m == 1 ) return 1;
	long ketQua= 0;
	for(int i= 0; i < (n/m); i++)
	{
//		int S= n-1;
		ketQua= ( ketQua + chia1SoThanhNhieuTong( n -i*m -1, m-1, M) ) % M;
//      cout << n << " : " << m << " + ( " << n - i*m -1<< "," << m-1 << ") = " << ketQua << endl;
	}
//    else ketQua= ( ketQua + chia1SoThanhNhieuTong( n-1, m-1, M) ) % M;
    return ketQua;
}

long xep_n_BiThanh_m_PhanNhoHon( int n, int m, int M)
{
	if( min(n, m) < 2 ) return 1;
	long ketQua= n/2 + 1;
	for(int i= 3; i <= min( n, m); i++)
	{
		ketQua= (ketQua + chia1SoThanhNhieuTong( n, i, M) )% M;
		cout << i << "  =   " << ketQua << endl;
	}
	return ketQua;
}

main()
{
	int n, m;
	long M;
	cin >> n >> m >> M;
	cout << xep_n_BiThanh_m_PhanNhoHon( n, m, M);
}


/*
long xep_n_BiThanh_m_Phan(int n, int m, int M)
{
//	cout << n << " ;  " << m << endl;
//  if( m == 0 ) return 0;
//  if( m == 1 ) return 1;
//	int dem_m= 1;
	long ketQua= 0;
	if( n >= 2*m )
    {
		ketQua= ( ketQua + xep_n_BiThanh_m_Phan( n - m	, m 				   , M) )%M;
        cout << n << " : " << m << " + ( " << n - m << "," << m << ") = " << ketQua << endl;
    }
    if( n >= m )
    {
        ketQua= ( ketQua + xep_n_BiThanh_m_Phan( n - m  , min(m - 1 , n - m)    , M) )%M;
		ketQua= ( ketQua + xep_n_BiThanh_m_Phan( n      , m - 1                 , M) )%M;
        cout << n << " : " << m << " + ( " << n - m << "," << min(m -1, n - m) << ") = " << ketQua << endl;
        cout << n << " : " << m << " + ( " << n << "," << m - 1 << ") = " << ketQua << endl;
    }
    if( m > n && n > 1 )4
    {
        ketQua= ( ketQua + xep_n_BiThanh_m_Phan( n      , n     		, M) )%M;
    }
	return ketQua;
}
*/













