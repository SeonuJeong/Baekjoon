#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
int N,M;

vector<int> adj[10001];
int visited[10001];

int dfs(int here){
	visited[here]=1;
	int cnt=1;
	for(int i=0;i<adj[here].size();i++){
		int there = adj[here][i];
		
		if(!visited[there])
			cnt+=dfs(there);
	}
	
	return cnt;
}


void solve(){
	cin>>N>>M;
	
	for(int i=0;i<M;i++){
		int A,B;cin>>A>>B;	
		adj[B].push_back(A);
	}
	vector<pair<int,int>> v;
	for(int i=1;i<=N;i++){
		memset(visited,0,sizeof(visited));
		v.push_back({dfs(i),-i});
	}
	sort(v.begin(),v.end());
	
	
	for(int i=v.size()-1;i>=0;i--){
		if(i!=v.size()-1&&v[i].first!=v[i+1].first){
			break;
		}
		cout<<abs(v[i].second)<<" ";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
