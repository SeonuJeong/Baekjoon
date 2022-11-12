#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;


void solve(){
	
	int N,M;
	cin>>N>>M;
	
	unordered_map<int,int> um;
	
	for(int i=0;i<N; i++){
		int num;
		cin>>num;
		um[num]=i;
	}
	
	int cnt=0;
	for(auto it:um){
		if(um.find(M-it.first)==um.end())
			continue;
		
		if(um[M-it.first]>it.second)
			cnt++;
	}
	
	cout<<cnt<<"\n";
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
