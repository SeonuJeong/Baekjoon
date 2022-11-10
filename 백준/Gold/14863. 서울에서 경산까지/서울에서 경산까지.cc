#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const ll INF = 1e18;

vector<vector<ll>> v;
int N,K;
ll dp[101][100001];

ll go(int idx,int remain){
	
	if(remain<0){
		return -INF;
	}
	
	if(idx==N){
		return 0;
	}
	
	ll& ret=dp[idx][remain];
	
	if(ret!=-1)
		return ret;
	
	ret=0;
	
	ret=max(ret,go(idx+1,remain-v[idx][0])+v[idx][1]);
	ret=max(ret,go(idx+1,remain-v[idx][2])+v[idx][3]);
	
	if(!ret)
		ret=-INF;
	
	return ret;
}

void solve(){
	cin>>N>>K;
	memset(dp,-1,sizeof(dp));
	
	rep(i,0,N){
		ll a,b,c,d;cin>>a>>b>>c>>d;
		vector<ll> tmp={a,b,c,d};
		v.push_back(tmp);
	}
	
	cout<<go(0,K);
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
