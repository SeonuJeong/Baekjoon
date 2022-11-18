#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,M;
bool m[41];
int dp[41][2];

int go(int pos,int enable){
	
	if(pos==N+1){
		return 1;
	}
	
	int& ret=dp[pos][enable];
	
	if(ret!=-1)
		return ret;
	
	if(m[pos]||!enable){
		ret=go(pos+1,1);
		return ret;
	}
		
	ret=0;
	
	if(pos+1<=N&&!m[pos+1]){
		ret+=go(pos+1,0);
	}
	
	ret+=go(pos+1,1);
	return ret;
}

void solve(){
	cin>>N>>M;
	
	rep(i,0,M){
		int c;cin>>c;
		m[c]=1;
	}
	memset(dp,-1,sizeof(dp));
	cout<<go(1,1);
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
