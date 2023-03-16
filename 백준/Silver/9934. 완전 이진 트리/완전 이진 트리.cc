#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
int K;
vector<int> v;
int idx=0;
vector<int> level[10];
void dfs(int depth){
	
	if(depth==K){
		level[depth-1].push_back(v[idx++]);
		return;
	}
	
	dfs(depth+1);
	level[depth-1].push_back(v[idx++]);
	dfs(depth+1);
}

void solve(){
	cin>>K;

	rep(i,0,(int)(pow(2,K))-1){
		int c;cin>>c;
		v.push_back(c);
	}
	dfs(1);
	rep(i,0,K){
		rep(j,0,level[i].size()){
			cout<<level[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}
int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
