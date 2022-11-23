#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

/**
	O(n^2) 다익스트라 
	O(n^2*t) 경로 추적 
*/
int n,m,t;
int s,g,h;
int adj[2001][2001]; 
int dist[2001];
int visited[2001];
vector<int> candi;
void solve(){
	cin>>n>>m>>t;
	cin>>s>>g>>h;
	
	memset(adj,-1,sizeof(adj));
	fill(dist,dist+2001,INF);
	memset(visited,0,sizeof(visited));
	candi.clear();
	
	rep(i,0,m){
		int a,b,d; cin>>a>>b>>d;
		adj[a][b]=d;
		adj[b][a]=d;
	}
	
	rep(i,0,t){
		int tmp; cin>>tmp;
		candi.push_back(tmp);
	}
	sort(candi.begin(),candi.end());
	
	//다익스트라
	dist[s]=0;
	for(int i=0;i<n-1;i++){
		int idx=1;
		int val=INF;
		
		rep(j,1,n+1)
			if(!visited[j]&&val>dist[j]){
				idx=j;
				val=dist[j];
			}
		
		visited[idx]=true;
		
		rep(j,1,n+1){
			if(visited[j]) continue;
			if(adj[idx][j]==-1) continue;
			if(dist[idx]+adj[idx][j]<dist[j])
				dist[j]= dist[idx]+adj[idx][j];
		}
	}
	

	//추적
	int route[2001];
	memset(route,0,sizeof(route));
	
	queue<int> que;
	
	if(dist[g]==dist[h]+adj[h][g]){
		que.push(g);
		route[g]=1;
	}
	if(dist[h]==dist[g]+adj[g][h]){
		que.push(h);
		route[h]=1;
	}
		
		
	while(que.size()){
		int cur=que.front(); que.pop();
		
		rep(j,1,n+1){
			if(adj[cur][j]==-1) continue;
			
			if(route[j]!=1&&dist[j]==dist[cur]+adj[cur][j]){
				route[j]=1;
				que.push(j);
			}
		}
	}
	
	rep(i,0,candi.size()){
		if(route[candi[i]])
			cout<<candi[i]<<" ";
	}
	
	cout<<"\n";
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	int T;
	cin>>T;
	while(T--){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}
