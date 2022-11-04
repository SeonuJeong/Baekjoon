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
ll dp[31][61];
ll go(int ori,int half){
	
	if(ori==0&&half==0){
		return 1;
	}
	
	ll& ret=dp[ori][half];
	
	if(ret!=-1)
		return ret;
	
	ll cnt=0;
	if(ori>0){
		cnt+=go(ori-1,half+1);
	}
	
	if(half>0){
		cnt+=go(ori,half-1);
	}
	
	ret=cnt;
	
	return cnt;
}

int solve(){
	cin>>N;
	memset(dp,-1,sizeof(dp));
	if(N==0) return 0;
	
	cout<<go(N,0)<<"\n";
	
	return 1;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	while(solve()){
		
	}
}
