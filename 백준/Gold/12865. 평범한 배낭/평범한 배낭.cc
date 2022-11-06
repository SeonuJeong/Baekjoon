#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,K;

int dp[100001];


void solve(){
	cin>>N>>K;
	
	rep(i,0,N){
		int W,V;cin>>W>>V;
	
		for(int j=K;j>=W;j--){
			dp[j]=max(dp[j],dp[j-W]+V);
		}
	}
	
	cout<<dp[K];
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
