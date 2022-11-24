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
vector<int> adj[100001];
vector<int> adjIn[100001];
int visited[100001];

int dfs(int here){
	
	int cnt=0;
	for(int next:adj[here]){
		if(visited[next]) continue;
		visited[next]=1;
		cnt+=dfs(next);
	}
	
	return cnt+1;
}

int dfsIn(int here){
	
	int cnt=0;
	for(int next:adjIn[here]){
		if(visited[next]) continue;
		visited[next]=1;
		cnt+=dfsIn(next);
	}
	return cnt+1;
}

void solve(){
	cin>>N>>M>>X;
	
	rep(i,0,M){
		int a,b; 
		cin>>a>>b;
		adj[a].push_back(b);
		adjIn[b].push_back(a);
	}
	
	
	int u=dfsIn(X);
	memset(visited,0,sizeof(visited));
	int v=(N-dfs(X)+1);
	cout<<u<<" "<<v;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
