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
int at[3]={9,3,1};
int dp[61][61][61];
int go(vector<int> v){
	
	if(v.empty()){
		return 0;
	}
	
	vector<int> p(3,0);
	
	rep(i,0,v.size())
		p[i]=v[i];

	int &ret=dp[p[0]][p[1]][p[2]];
	
	if(ret!=-1)
		return ret;
	
	sort(v.begin(),v.end());
	
	int cnt=INF;
	do{
		vector<int> tmp;
		rep(i,0,v.size()){
			if(v[i]-at[i]>0)
				tmp.push_back(v[i]-at[i]);
		}
			
		cnt=min(cnt,go(tmp)+1);
	}while(next_permutation(v.begin(),v.end()));
	
	ret=cnt;
	
	return cnt;
}

void solve(){
	cin>>N;
	memset(dp,-1,sizeof(dp));
	vector<int> v;	
	rep(i,0,N){
		int c;cin>>c;
		v.push_back(c);
	}
		
	cout<<go(v);
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
