#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,M,C;
int maps[51][51];
ll dp[51][51][51][51];
ll mod=1000007;
ll go(int r,int c,int cnt,int cur){
	
	if(r==N&&c==M){
		
		if(maps[r][c]){
			if(maps[r][c]>cur)
				cnt=cnt-1;
			else
				return 0;
		}
		
		if(cnt==0) return 1;
		else return 0;
	}
	
	if(r>N||c>M||cnt<0)
		return 0;
		
	ll& ret=dp[r][c][cnt][cur];
	
	if(ret!=-1)
		return ret;
	
	ll val=0;

	if(!maps[r][c])
		val+=(go(r+1,c,cnt,cur)+go(r,c+1,cnt,cur))%mod;
	else if(maps[r][c]>cur){
		val+=(go(r+1,c,cnt-1,maps[r][c])+go(r,c+1,cnt-1,maps[r][c]))%mod;
	}
	ret=val;
	return ret;
}

void solve(){
	cin>>N>>M>>C;
	
	memset(dp,-1,sizeof(dp));
	
	rep(i,0,C){
		int r,c;cin>>r>>c;
		maps[r][c]=i+1;
	}
	
	
	rep(i,0,C+1){
		cout<<(go(1,1,i,0)%mod)<<" ";
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
	
}
