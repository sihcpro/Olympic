#include <iostream>

using namespace std;

void taoBang() {
long a[1001] ;
int number , n;
long M;
    cin>>number >> n >> M;
     /**< khoi tao gia tri ban dau */
    a[0] = 1 ;
     for(int m = 1 ; m<=number ; m++)
        a[m]  = 0 ;
    /**< dien vao bang ket qua */

    for(int m = 1 ; m<=n ; m++) {
        for(int v = m ; v<=number ; v++) {
                a[v] = ( a[v] + a[v-m] ) % M;
        }
    }

    cout <<a[number] ;

}

int main()
{

   taoBang() ;

    return 0;
}
