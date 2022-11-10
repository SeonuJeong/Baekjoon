#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

vector<int> v;
int dp[100001][5][5];
int go(int pos,int le,int ri){
	
	if(pos==v.size()){
		return 0;
	}
	
	int& ret=dp[pos][le][ri];
	
	if(ret!=-1)
		return ret;
	
	int val=INF;
	if(le==v[pos]||ri==v[pos]){
		val=min(val,go(pos+1,le,ri)+1);
		
		ret=val;
		return ret;
	}
	
	
	if(le==0){
		val=min(val,go(pos+1,v[pos],ri)+2);
	}
	else{
		if(abs(le-v[pos])==1||abs(le-v[pos])==3)
			val=min(val,go(pos+1,v[pos],ri)+3);
		else
			val=min(val,go(pos+1,v[pos],ri)+4);
	}
	
	if(abs(ri-v[pos])==1||abs(ri-v[pos])==3)
		val=min(val,go(pos+1,le,v[pos])+3);
	else
		val=min(val,go(pos+1,le,v[pos])+4);
		
	ret=val;
	return val;
}
void solve(){
	while(1){
		int c;cin>>c;
		if(c==0) break;
		v.push_back(c);
	}
	memset(dp,-1,sizeof(dp));
	
	cout<<(go(1,0,v[0])+2);
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
