#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int V,E,K;

vector<pi> adj[20001]; 
int dist[20001];
priority_queue<pi,vector<pi>,greater<pi>> pq;

void solve(){
	cin>>V>>E>>K;
	
	fill(&dist[0],&dist[0]+20001,INF);
	
	rep(i,0,E){
		int u,v,w; cin>>u>>v>>w;
		adj[u].push_back({w,v});
	}

	
	pq.push({0,K});
	dist[K]=0;
	
	while(pq.size()){
		int here=pq.top().s;
		int here_dist=pq.top().f; pq.pop();
		
		
		if(dist[here]!=here_dist) continue;
		
		
		for(pi there: adj[here]){
			int _dist=there.f;
			int _there=there.s;
			
			if(dist[_there]>dist[here]+_dist){
				dist[_there]=dist[here]+_dist;
				pq.push({dist[_there],_there});
			}
			
		}
	}
	
	rep(i,1,V+1)
		if(dist[i]==INF)
			cout<<"INF\n";
		else
			cout<<dist[i]<<"\n";
	
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
