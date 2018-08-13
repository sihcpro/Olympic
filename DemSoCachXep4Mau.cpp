#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long mu2(long n)
{
    long long m= 1;
    for(int i= 1; i <= n; i++)
    {
        m= m<< 1;
        m%= 10007;
    }
    return m%10007;
}

long long giaiThua( long i, long n )
{
    long long m=1;
    for(; i <= n; i++ )
    {
        m*= (i%10007);
        m%= 10007;
    }
    return m%10007;
}

long long nCk( long n, long k)
{
    if ( k >= n ) return 1;
    if ( k >= n-k )
        return giaiThua(k+1, n) / giaiThua(2, n-k);
    else
        return giaiThua(n-k+1, n) / giaiThua(2, k);

}

main()
{
    long n;
    long long dem= 0;
    cin >> n;
    if (n < 10007)
    for(long i= 0; i <= n/2; i++)
    {
        long long tam=1;
        tam*= nCk(n, i*2)*mu2(i);
        tam%= 10007;
        tam*= mu2(n-i*2);
        tam%= 10007;
        dem+= tam;
        dem%= 10007;
    }

/*
    for(long i= 0; i <= n/2; i++)
    {
        for(long j= 0; j <= n/2-i; j++)
        {
            for(long k= 0; k <= n-i*2-j*2; k++)
            {
                long long tam= 1;
                tam*= nCk( i*2+j*2   , i*2       );         //Chi tinh 2 mau Do va Tim
                tam*= nCk( i*2+j*2+k , i*2+j*2   );         //Them mau Xanh hoac Vang
                tam*= nCk( n         , i*2+j*2+k );         //Them mau con lai
                dem+= tam;
            }
        }
    }
*/
    cout << dem;
}
