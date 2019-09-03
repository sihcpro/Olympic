#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep( bg, i, num ) for(ll (i)= (bg); (i) < (num); ++(i))
#define repd( num, i, ed ) for(ll (i)= (num)-1; (i) >= ed; --(i))
#define repkt( bg, i, num, kt ) for(ll (i)= (bg); (i) < (num) && (kt); ++(i))
#define repchar( i ) for(char (i)= 48; (i) <= 122; (i)++)

vector<int> z_function(string s) {
	int n = (int) s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("test.txt", "r", stdin);

	string s;
	while(cin >> s) {
		vector<int> v = z_function(s);
		rep(0, i, v.size()) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
}
