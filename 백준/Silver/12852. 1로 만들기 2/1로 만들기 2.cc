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
int dp[1000001];
vector<int> v;

int go(int n){
	
	if(n==1){
		return 0;
	}
		
	
	int& ret=dp[n];
	
	if(ret!=-1)
		return ret;
	
	int cnt=INF;		
	if(n%3==0)
		cnt=min(cnt,go(n/3)+1);
	
	if(n%2==0)
		cnt=min(cnt,go(n/2)+1);
		
	cnt=min(cnt,go(n-1)+1);
	
	ret=cnt;
	return cnt;
}

void go2(int n){
	
	cout<<n<<" ";
	
	if(n==1) return ;

	int next=n-1;
	
	if(n%2==0&&dp[next]>dp[n/2])
		next=n/2;
	
	if(n%3==0&&dp[next]>dp[n/3])
		next=n/3;
		
	go2(next);
}

void solve(){
	cin>>N;
	memset(dp,-1,sizeof(dp));
	cout<<go(N)<<"\n";
	
	go2(N);
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
