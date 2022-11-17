#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

vector<pi> cse;
int N,W;

int dp[1003][1003];

int cal(int a,int b){
	
	return abs(cse[a].f-cse[b].f)+abs(cse[a].s-cse[b].s);
	
}

int go(int c1,int c2){
	
	if(c1==W+1||c2==W+1){
		return 0;
	}
	
	int& ret=dp[c1][c2];
	
	if(ret!=-1)
		return ret;
	
	ret=INF;
	int next=max(c1,c2)+1;
	ret=min(go(c1,next)+cal(c2,next), go(next,c2)+cal(c1,next));
	
	return ret;
}


void solve(){
	cin>>N>>W;
	memset(dp,-1,sizeof(dp));
	
	cse.push_back({1,1});
	cse.push_back({N,N});	
	rep(i,0,W){
		int a,b; cin>>a>>b;
		cse.push_back({a,b});
	}
	
	cout<<go(0,1)<<"\n";
	
	int c1=0,c2=1;
	for(int i=2;i<W+2;i++){
		
		if(cal(c1,i)+go(i,c2)<cal(c2,i)+go(c1,i)){
			c1=i;
			cout<<"1\n";
		}
		else{
			c2=i;
			cout<<"2\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
	solve();
}
