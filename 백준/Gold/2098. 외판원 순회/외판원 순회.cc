#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N;
int v[17][17];
int dp[1<<16][17];

int go(int visited,int cur){
	
	if(visited==(1<<N)-1){
		return v[cur][0]?v[cur][0]:INF;
	}
	
	int &ret=dp[visited][cur];
	if(ret!=-1)
		return ret;
	
	ret=INF;
	rep(i,0,N){
		if(visited&(1<<i))continue;
		if(!v[cur][i])continue;
		
		ret=min(ret,go(visited|(1<<i),i)+v[cur][i]);
	}
	
	return ret;
}

void solve(){
	cin>>N;
	memset(dp,-1,sizeof(dp));
	
	int end=(1<<N)-1;	
	
	rep(i,0,N)
		rep(j,0,N)
			cin>>v[i][j];
	
	cout<<go(1,0);
	
}

int main() {



	solve();
}
