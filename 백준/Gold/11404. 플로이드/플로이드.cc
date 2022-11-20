#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int n,m;
vector<pi> adj[101];
int dist[101];
priority_queue<pi> pq;
void solve(){
	cin>>n>>m;
	
	rep(i,0,m){
		int a,b,c; cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	
	rep(i,0,n){
		fill(dist,dist+101,INF);
		dist[i+1]=0;
		pq.push({0,i+1});
		
		while(pq.size()){
			int here=pq.top().s;
			int here_dist=pq.top().f;
			pq.pop();
			
			if(dist[here]!=here_dist) continue;
			
			for(pi there:adj[here]){
				int _there=there.f;
				int _dist=there.s;
				
				if(dist[_there]>dist[here]+_dist){
					dist[_there]=dist[here]+_dist;
					pq.push({dist[_there],_there});
				}
			}
		}
		
		rep(j,0,n){
			if(dist[j+1]!=INF)
				cout<<dist[j+1]<<" ";
			else
				cout<<0<<" ";
		}
		cout<<"\n";
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
