#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > min_heap;
    string number;
    int num= 0;
    
    getline(cin, number);
    for(unsigned int i= 0; i <= number.size(); i++)
    {
    	if( number[i] == ' ' ||  i == number.size() )
    	{
    		if( number[i-1] != ' ' ) min_heap.push(num);
    		num= 0;
    	}
    	else
    	{
    		num= num*10 + ( number[i] & 0xF );
    	}
    }
    cout << min_heap.top();
    return 0;
}