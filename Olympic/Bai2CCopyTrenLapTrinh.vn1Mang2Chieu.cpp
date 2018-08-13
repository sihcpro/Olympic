#include <iostream>

using namespace std;
    int number ;
    int a[100][100] ;

void taoBang() {
    cin>>number ;
     /**< khoi tao gia tri ban dau */
    a[0][0] = 1 ;
    for(int m = 1 ; m<=number ; m++)
        a[0][m] = 0 ;
    /**< dien vao bang ket qua */
    for(int m = 1 ; m<=number ; m++) {
        for(int v = 0 ; v<=number ; v++) {
            if(m>v) {
                a[m][v] = a[m-1][v] ;
            }
            else {
                a[m][v] = a[m-1][v] + a[m][v-m] ;
            }
        }
    }

}
void inKetQua() {
    /**< In bang */
    for(int m = 0 ; m<=number ; m++) {
        for(int v = 0 ; v<=number ; v++) {
                cout<<a[m][v]<<" " ;
        }
        cout<<endl ;
    }
    /**< in so ket qua */
    cout<<"Tong so " << a[number][number] <<endl ;
}
int main()
{

   taoBang() ;
   inKetQua() ;
    return 0;
}
xalloc