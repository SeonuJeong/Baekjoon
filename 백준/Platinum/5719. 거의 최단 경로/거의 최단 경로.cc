#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

vector<int> m[501];
bool removed[501][501];

int s,d;

void remove(int here){
	
	if(s==here){
		return ;
	}
	
	for(int before: m[here]){
		
		if(removed[before][here]) continue;
		
		removed[before][here]=1;
		removed[here][before]=1;
		
		remove(before);
	}
	
}

int solve(){
	int n,M; cin>>n>>M;
	memset(removed,0,sizeof(removed));
	if(n==0&&M==0) return 0;
	
	cin>>s>>d;
	
	int dist[501];
	vector<pi> adj[501];
	
	fill(dist,dist+501,INF);
	
	rep(i,0,501){
		m[i].clear();
	}
	
		
	rep(i,0,M){
		int u,v,p; cin>>u>>v>>p;
		adj[u].push_back({p,v});
	}
	
	priority_queue<pi> pq;
	dist[s]=0;
	pq.push({0,s});
	
	while(pq.size()){
		int here,here_dist;
		tie(here_dist,here)=pq.top(); pq.pop();
		
		if(here_dist!=dist[here]) continue;
		
		for(pi there:adj[here]){
			int _there=there.s;
			int _dist=there.f;
			
			if(dist[_there]>dist[here]+_dist){
				m[_there].clear();
				m[_there].push_back(here);
				
				dist[_there]=dist[here]+_dist;
				pq.push({dist[_there],_there});
			}
			else if(dist[_there]==dist[here]+_dist){
				m[_there].push_back(here);
			}
		}
	}
	
	
	if(dist[d]==INF){
		cout<<"-1\n";
		return 1;
	}
		
	
	remove(d);
	
	fill(dist,dist+501,INF);
	
	dist[s]=0;
	pq.push({0,s});
	
	while(pq.size()){
		int here,here_dist;
		tie(here_dist,here)=pq.top(); pq.pop();
		
		if(here_dist!=dist[here]) continue;
		
		for(pi there:adj[here]){
	
			int _there=there.s;
			int _dist=there.f;
			
			if(removed[here][_there]) continue;
			
			if(dist[_there]>dist[here]+_dist){
				dist[_there]=dist[here]+_dist;
				pq.push({dist[_there],_there});
			}
		}
	}
	
	if(dist[d]==INF)
		cout<<"-1\n";
	else	
		cout<<dist[d]<<"\n";
	
	return 1;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	while(solve()){
		
	}
}
