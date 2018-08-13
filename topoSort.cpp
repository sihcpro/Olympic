stack<int> st;
bool b[300005];
void sortTopo(int i){
	b[i]= true;
	vector<int> v= a[i].v;
	rep(0,j,v.size()){
		if( !b[ v[j] ] )
			sortTopo( v[j] );
	}
	st.PU(i);
}

main(){
	rep(1,i,n+1){
		if( !b[i] )
			sortTopo(i);
	}
}
