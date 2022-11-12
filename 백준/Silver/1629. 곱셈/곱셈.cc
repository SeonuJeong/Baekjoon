#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
const int INF = 1e9;

ll A,B,C;

ll func(ll n){
	
	if(n==1){
		return A%C;
	}
	
	
	if(n%2==0){
		return (func(n/2)*func(n/2))%C;
	}
	else{
		return ((A%C)*func(n-1))%C;
	}
	
}

void solve(){

	cin>>A>>B>>C;
	
	if(A%C==0){
		cout<<"0\n";
		return;
	}
	
	cout<<func(B);
}



int main() {

	ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

//	int t,i=1;
//	cin>>t;
//	while(t--){
//		//cout<<"Case #"<<i<<": ";
//		solve();
//		i++;
//	}
	solve();
}
