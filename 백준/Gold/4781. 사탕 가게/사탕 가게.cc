#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int dp[10001];
vector<pi> v;	
int go(int money){
	
	if(money==0){
		return 0;
	}
	
	int& ret=dp[money];
	
	if(ret!=-1)
		return ret;
	
	int maxVal=0;
	
	rep(i,0,v.size()){
		if(v[i].s>money) continue;
		
		maxVal=max(maxVal,v[i].f+go(money-v[i].s));
	}
	
	ret=maxVal;
	return maxVal;
}

int chg(string s){
	int ret=0;
	
	rep(i,0,s.length()){
		if(s[i]=='.') continue;
		
		ret=ret*10+(s[i]-'0');
	}
	return ret;
}

int solve(){
	
	int n,m; cin>>n;
	string s;
	cin>>s;
	m=chg(s);
	
	if(n==0&&m==0)
		return 0;
	
	
	v.clear();
	memset(dp,-1,sizeof(dp));
	
	rep(i,0,n){
		int c,p; cin>>c>>s;
		p=chg(s);
		
		v.push_back({c,p});
	}
	
	cout<<go(m)<<"\n";
	return 1;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
	while(solve()){
		
	}
}
