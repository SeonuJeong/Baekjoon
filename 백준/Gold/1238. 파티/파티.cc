#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N,M,X;
//vector<pi> adj[1001];
int dist[1001][1001];
void solve(){
	cin>>N>>M>>X;
	
	fill(&dist[0][0],&dist[0][0]+1001*1001,INF);
	rep(i,0,M){
		int s,e,t; cin>>s>>e>>t;
		//adj[s].push_back({t,e});
		dist[s][e]=dist[s][e]?min(dist[s][e],t):t;
	}
	
	
	rep(k,1,N+1)
		rep(i,1,N+1)
			rep(j,1,N+1)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);			
	
	int ret=0;
	rep(i,1,N+1){
		if(i==X) continue;
		ret=max(ret,dist[i][X]+dist[X][i]);
		//cout<<dist[i][X]<<" "<<dist[X][i]<<"\n";
	}
	cout<<ret;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
