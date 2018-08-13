/*
C. NGUYÊN ÂM
Cho một xâu S, tìm số xâu con của nó có chứa đúng 3 nguyên âm.
Các kí tự trong xâu S không giới hạn.
Xâu con của S là xâu chứa các kí tự liên tiếp của S. Ví dụ xâu “abc” chưa các xâu
con là “a”, “b”, “c”, “ab”, “bc”, “abc”.
Input
Dòng thứ nhất gồm T – số test.
Mỗi test gồm 2 dòng, dòng 1 là số nguyên N – độ dài xâu, dòng 2 là xâu S độ dài
N.
Output
Gồm T dòng, với mỗi test in ra kết quả bài toán trên một dòng.
Giới hạn
1 <= T <= 20
1 <= N <= 100000
Sample Input Sample Output
1
5
aebco
1
Giải thích: Chỉ có 1 xâu con duy nhất của S có chứa đúng 3 nguyên âm và đó cũng
chính là xâu S
Nguyên âm bao gồm các kí tự ‘a’, ‘e’, ‘i’, ‘o’, ‘u’
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

using namespace std;

#define mod 10000009ll
#define fori(n) for(ll i= 1; i <= n; i++)
#define forj(n) for(ll j= 1; j <= n; j++)
#define in(n) scanf("%I64d", &n)
#define out(n) printf("%I64d\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef long long ll;
typedef priority_queue<ll> pqmax;
typedef priority_queue<long, vector<long>, greater<long> > pqmin;


ll t, m, sp, junger, mid, top, bot, x, y;
ll n= 0, k= 0, a, b;
ll test;
bool kt;
char na[5]= { 'a', 'e', 'i', 'o', 'u' };
string s;

int main()
{
    cin >> test;

	while( test-- )
	{
        cin >> n >> s;

        t= 0;
        top= 0;
        bot= 0;
        sp= 0;
        a= 0;
        b= -1;
        while( top <= s.length() )
		{
            if( sp < 4 )
			{
                for(int i= 0; i < 5; i++)
					if( s[top] == na[i] )
					{
						sp++;
						if( sp == 3 && a == 0 )	a= top+1;
						break;
					}
                top++;
			}
			else
			{
                for(int i= 0; i < 5; i++)
					if( s[bot] == na[i] )
					{
						t+= (bot-b)*(top-a);
						sp--;
						b= bot;
						a= top;
						break;
					}
                bot++;
			}
		}
		while( sp == 3 )
		{
                for(int i= 0; i < 5; i++)
					if( s[bot] == na[i] )
					{
						t+= (bot-b)*(top-a);
						sp--;
						b= bot;
						a= top;
						break;
					}
                bot++;
		}

		cout << t << endl;
	}
}

