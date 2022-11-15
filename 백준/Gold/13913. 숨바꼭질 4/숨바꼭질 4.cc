#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
//0810

int N,K;
int visited[200001];
int parent[200001];
void bfs(){
	
	queue<int> que;
	que.push(N);
	visited[N]=0;
	parent[N]=-1;
	
	while(!que.empty()){
			
		int x=que.front(); que.pop();
		//cout<<x<<":"<<visited[x]<<"\n";
		if(x==K)
			break;
		
		
		rep(i,0,3){
			int nx;
			if(i==0&&x<K)
				nx=x+1;
			else if(i==1)
				nx=x-1;
			else if(x<K) 
				nx=x+x;
			else continue;
			
			if(nx<0) continue;
			
			if(visited[nx]!=-1)
				continue;
			
			
			visited[nx]=visited[x]+1;
			parent[nx]=x;
			que.push(nx);
		}
	}
	
}


void solve(){
	memset(visited,-1,sizeof(visited));
	memset(parent,0,sizeof(parent));
	
	cin>>N>>K;
	
	bfs();
	
	cout<<visited[K]<<"\n";
	
	int here=K;
	vector<int> route;
	while(parent[here]!=-1){
		route.push_back(here);
		here = parent[here];
	}
	route.push_back(here);
	
	for(int i=route.size()-1;i>=0;i--){
		cout<<route[i]<<" ";
	}
}



int main() {

//	ios_base::sync_with_stdio(false);
//    cout.tie(nullptr);
//    cin.tie(nullptr);

	solve();
}
