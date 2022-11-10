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
vector<int> v;
int result;

ll dp[101][901][2];
ll go(int pos,int val,int method){
	
	if(pos==v.size()){
		if(val==result)
			return 1;
		else
			return 0;
	}
	
	
	if(method)
		val+=v[pos];
	else
		val-=v[pos];
		
	if(val<0||val>20)
		return 0;
	
	ll& ret=dp[pos][val][method];
	if(ret!=-1)
		return ret;
		
	ll cnt=0;
	cnt+=go(pos+1,val,1);
	cnt+=go(pos+1,val,0);
	
	if(pos==v.size()-1)
		cnt=cnt/2;
		
	ret=cnt;
	return cnt;
}

void solve(){
	cin>>N;
	memset(dp,-1,sizeof(dp));
	
	rep(i,0,N-1){
		int c;cin>>c;
		v.push_back(c);
	}
	cin>>result;
	
	cout<<(go(1,v[0],1)+go(1,v[0],0));
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
