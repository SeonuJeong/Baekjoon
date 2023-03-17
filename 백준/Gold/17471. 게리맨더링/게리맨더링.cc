#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
//0150

int N;
int v[10];
vector<int> adj[10];
int visited[10];
int state;

int check(int i){
	if((state&(1<<i))==0)
		return 0;
	else
		return 1;
}

int dfs(int cur){
	
	visited[cur]=1;
	
	int cnt=1;
	for(int i=0;i<adj[cur].size();i++){
		if(visited[adj[cur][i]]) continue;
		
		if(check(cur)==check(adj[cur][i])){
			cnt+=dfs(adj[cur][i]);
		}
	}
	return cnt;
}

void solve(){
	cin>>N;
	
	rep(i,0,N)
		cin>>v[i];
		
	rep(i,0,N){
		int l; cin>>l;
		
		rep(j,0,l){
			int next;cin>>next;
			adj[i].push_back(next-1);
		}
	}
	
	int minValue=INF;
	
	for(state=0;state<(1<<N);state++){
		memset(visited,0,sizeof(visited));
		
		int A=0,B=0;
		
		rep(i,0,N){
			if((state&(1<<i))==0){
				//cout<<"A\n";
				A = dfs(i);
				break;
			}
		}
		
		rep(i,0,N){
			if(state&(1<<i)){
				//cout<<"B\n";
				B = dfs(i);
				break;
			}
		}
		//cout<<A<<" "<<B<<"\n";
		if(A+B!=N||A==0||B==0) continue;
		
		A=0;B=0;
		
		rep(i,0,N){
			if((state&(1<<i))==0){
				A+=v[i];
			}
			else
				B+=v[i];
		}
		
		minValue=min(minValue,abs(A-B));
	}
	
	cout<<(minValue==INF?-1:minValue);
}



int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
