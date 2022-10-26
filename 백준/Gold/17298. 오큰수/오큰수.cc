#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int ans[1000000];

void solve(){
	memset(ans,-1,sizeof(ans));
	int N;cin>>N;
	vector<pair<int,int>> v;
	for(int i=0;i<N;i++){
		int a;cin>>a;
		
		if(v.empty()){
			v.push_back({a,i});
			continue;
		}
		
		while(!v.empty()&&v.back().first<a){
			ans[v.back().second]=a;
			v.pop_back();
		}
		
		v.push_back({a,i});
		
	}
	
	for(int i=0;i<N;i++){
		cout<<ans[i]<<" ";
	}
	
}



int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
