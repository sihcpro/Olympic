/*
B.CHIA HẾT
Cho dãy số nguyên A gồm N phần tử. Hãy tìm một tập nhỏ nhất gồm các phần tử liên
tiếp của dãy A sao cho tổng của tất cả phần tử thuộc dãy con liên tiếp này chia hết cho
N. Nếu có nhiều tập thỏa mãn điều kiện trên thì hãy in ra tập xuất hiện đầu tiên từ bên
trái sang.
Input :
Dòng 1 : T là số testcase. T<=10
Mỗi testcase gồm 2 dòng.
Dòng 1 : Số N <= 100000
Dòng 2 : N số nguyên dương. Các số nguyên dương không quá 1000000000.
Output :
Với mỗi testcase, in ra vị trí bắt đầu và vị trí kết thúc của dãy con liên tiếp cần tìm.
INPUT 			OUTPUT
2				3 2 3 6 4
4				1 1
4 1 4 4			1 2
5
*/



#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <fstream>
#include <string.h>
#include <set>

using namespace std;

#define mod 1000000007ll
#define fori(n) for(ll i= 0; i < n; i++)
#define forj(n) for(ll j= 0; j < n; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;
typedef priority_queue<ll> pqmax;
typedef priority_queue<long, vector<long>, greater<long> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y;
ll n= 0, k= 0, s, c;
ll test;

string s1, s2;

ll a[300005];

int main()
{
    in(test);

    while( test-- )
	{
        in(n);
        fori(n)
        {
			in(sp);
			a[i]= ( (sp-1) % n ) + 1;
        }

		sp= 0;
		fori(n)
		{
            sp+= a[i];
		}

        t= sp/n;

		m= n;
		ll bg= 0, ed= 0;
        for(ll i= 1; i <= t && m > i ; i++)
		{
			s= 0;
			bot= 0;
			top= 0;
			while( top <= n || m == 0 )
			{
				if( s < n*i )
				{
					s+= a[top];
					top++;
				}
				else
				{
					if( s == n*i && top - bot < m )
					{
						m= top-bot;
						bg= bot+1;
						ed= top;
					}
					s-= a[bot];
					bot++;
				}
			}
		}

		cout << bg << " " << ed << endl;
	}
}

