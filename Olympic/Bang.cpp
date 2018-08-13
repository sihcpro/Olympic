#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

long a[10005];
int main(){
	int n;
	long long max;
	ifstream in("SUB.INP");
	in >> n >> max;

	for(int i= 0; i < n; i++)
	{
		in >> a[i];
	}
	long long z = 0;
//	for(int i = 0; i < n; i++){
//		z = z + a[i];
//		a[i] = z;
//		printf(" %ld",a[i]);
//	}
	int final_length = 0;
	int max_length = 0;
	long long temp = a[0];
	int j = 0, k = 0;
	while(temp < max || k < n) {
		if(temp < max){
			k++;
			temp += a[k];
		} else {
			temp -= a[j];
			if(k - j + 1 < max_length || max_length == 0) max_length = k - j + 1;
			j++;
		};
	}
	printf("%d",max_length);

	ofstream out("SUB.OUT");
	out << max_length;
}
