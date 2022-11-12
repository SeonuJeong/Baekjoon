#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;


void solve(){
	int n;
	cin>>n;
	
	map<string,int> um;
	for(int i=0; i<n; i++){
		string a,b;
		cin>>a>>b;
		
		um[b]++;
	}
	
	int mul=1;
	for(auto it:um){
		mul = mul*(it.second+1);
	}
	
	cout<<mul-1<<"\n";
}



int main() {

	ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	int t,i=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<i<<": ";
		solve();
		i++;
	}

}
