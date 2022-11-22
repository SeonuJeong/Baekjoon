#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int n,k,s;
vector<int> adj[401];

bool dfs(int here,int there,vector<int>& visited){
	
	if(here==there){
		return true;
	}
	
	for(int next:adj[here]){
		if(visited[next]) continue;
		
		visited[next]=1;
		if(dfs(next,there,visited))
			return true;
	}
	
	return false;
}

void solve(){
	cin>>n>>k;
	
	rep(i,0,k){
		int _s,_e;cin>>_s>>_e;
		adj[_s].push_back(_e);
	}
	
	cin>>s;
	rep(i,0,s){
		int _s,_e; cin>>_s>>_e;
		
		vector<int> visited(401,0);
		
		if(dfs(_s,_e,visited)){
			cout<<"-1\n";
			continue;
		}
		
		rep(j,0,401)
			visited[j]=0;
			
		if(dfs(_e,_s,visited)) cout<<"1\n";
		else cout<<"0\n";
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
