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
int dp[10020][5];
int go(int cur,int plus){
	
	if(cur>N)
		return 0;
	else if(cur==N)
		return 1;
	else if(plus>3)
		return 0;
	
	if(dp[cur][plus]!=-1)
		return dp[cur][plus];
	
	dp[cur][plus]=go(cur+plus,plus)+go(cur,plus+1);
	return dp[cur][plus];
}

void solve(){
	cin>>N;
	memset(dp,-1,sizeof(dp));
	cout<<go(0,1)<<"\n";
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}
