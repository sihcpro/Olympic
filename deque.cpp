cin >> n;

stack<ll> s;

fori1(n)
{
	cin >> a[i];
}

s.push(0);
fori1(n)
{
	while( s.top() != 0 && a[s.top()] > a[i] ) s.pop();
	l[i]= s.top()+1;
	s.push(i);
}

while( !s.empty() ) s.pop();
s.push(n+1);
for(ll i= n; i>= 1; i--)
{
	while( s.top() != n+1 && a[s.top()] > a[i] ) s.pop();
	r[i]= s.top()-1;
	s.push(i);			
}
