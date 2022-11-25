#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

vector<int> adjIn[100001];
vector<int> adjOut[100001];
void solve(){
	
	int N,M;
	cin>>N>>M;
	
	rep(i,0,M){
		int x,y; cin>>x>>y;
		
		adjIn[x].push_back(y);
		adjOut[y].push_back(x);
	}
	
	set<int> s;
	vector<int> ret;
	rep(i,1,N+1){
		int cnt=adjIn[i].size()+(i-1-adjOut[i].size());
		//cout<<cnt+1<<"\n";
		ret.push_back(cnt+1);
		s.insert(cnt+1);
	}
	
	
	if(s.size()!=N){
		cout<<"-1\n";
		return;
	}
		
	rep(i,0,ret.size()){
		cout<<ret[i]<<" ";
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
