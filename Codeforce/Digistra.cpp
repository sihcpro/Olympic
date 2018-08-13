#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef priority_queue<long> pqmax;
typedef priority_queue<long, vector<long>, greater<long> > pqmin;

ll n;

typedef struct {
   int x,y;
} Egde;

int main()
{
	cin >> n;

    int t[n];
    vector<vector<Egde>> a;

    for(int i= 0; i < n+1; i++)
	{
        int s= i;
		while( s+= n < 2*n)
		{
			for(int j= 1; i < s/2; i++)
			{
				if( t[j] != 0 && t[s-j] != 0 )
				{
                    Egde tg;
                    tg.x= j;
                    tg.y= s-j;
                    vector<Egde> b;
                    b.push_back(tg);
                    a.push_back(b);
                    b[0];
				}
			}
		}
	}
}
