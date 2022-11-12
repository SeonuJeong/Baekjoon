#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;


void solve(){

	int pay[4];
	
	for(int i=0; i<3; i++){
		cin>>pay[i+1];
	}
	
	vector<int> cost(101,0);
	
	for(int i=0;i<3; i++){
		int s,e;
		cin>>s>>e;
		
		for(int j=s;j<e; j++){
			cost[j]++;
		}
	}
	
	int sum=0;
	
	for(int c:cost){
		sum+=c*pay[c];
	}
	cout<<sum;
}



int main() {

	ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	int t,i=1;
//	cin>>t;
//	while(t--){
//		//cout<<"Case #"<<i<<": ";
//		solve();
//		i++;
//	}

	solve();
	return 0;
}
