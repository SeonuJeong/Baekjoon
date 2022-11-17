#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,M,K,T;
int v[302];
int dp[301][301][301];
int go(int pos,int rk,int ck){

	if(pos==N+1){
		return 0;
	}
	
	int& ret=dp[pos][rk][ck];
	
	if(ret!=-1)
		return ret;
	
	int cur=v[pos]+ck;
	
	if(v[pos]>=T){
		cur=v[pos];
		ck=0;
	}
		
	if(cur>=T){
		
		ret=go(pos+1,rk,ck)+1;
		return ret;
	}
	
	ret=0;
	
	if(rk>=(T-cur)){
		ret=max(ret,go(pos+1,rk-(T-cur),(T-cur))+1);
	}
	
	ret=max(ret,go(pos+1,rk,ck));
	
	return ret;
}


void solve(){
	cin>>N>>M>>K>>T;
	
	rep(i,0,M){
		int a,b;cin>>a>>b;
		
		rep(j,a,b){
			v[j]++;
		}
	}

	memset(dp,-1,sizeof(dp));
	
	cout<<go(1,K,0);
	
}

int main() {
	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
	solve();
}
