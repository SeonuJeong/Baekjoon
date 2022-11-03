#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int T,W;
int v[1001];
int dp[1001][31];
int go(int pos,int move){
	
	if(pos==T)
		return 0;
	
	if(dp[pos][move]!=-1)
		return dp[pos][move];
	
	int get=v[pos]==(move%2+1)?1:0;
	
	int ret;
	if(move<W){
		ret=max(go(pos+1,move),go(pos+1,move+1))+get;
	}
	else
		ret=get+go(pos+1,move);
	
	dp[pos][move]=ret;
	return ret;
}

void solve(){
	cin>>T>>W;
	memset(dp,-1,sizeof(dp));
	rep(i,0,T)
		cin>>v[i];
		
	cout<<max(go(0,0),go(0,1));
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
