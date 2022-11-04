#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int n,k;
vector<int> v;
int dp[10001];
int go(int m){
	
	if(m==0) return 0;
	
	int& ret=dp[m];
	
	if(ret!=-1)
		return ret;
		
	int cnt=INF;
	rep(i,0,n){
		if(m-v[i]>=0){
			cnt=min(cnt,go(m-v[i])+1);
		}
	}
	
	ret=cnt;
	return cnt;
	
}
void solve(){
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	rep(i,0,n){
		int c;cin>>c;
		v.push_back(c);
	}
	
	int ret=go(k);
	cout<<(ret==INF?-1:ret);
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
	
}
