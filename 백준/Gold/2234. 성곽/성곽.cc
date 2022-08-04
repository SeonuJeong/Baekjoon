#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
//
int M,N;

int maps[50][50];
int visited[50][50];
int lnd=0;
int dy[]={0,-1,0,1};
int dx[]={-1,0,1,0};
vector<set<int>> adj;
vector<int> sv;

int dfs(int y,int x){
	visited[y][x]=lnd;
	
	int cnt=1;	
	rep(i,0,4){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||ny>=M||nx<0||nx>=N) continue;
		if(maps[y][x]&(1<<i)) continue;
		if(visited[ny][nx]!=-1) continue;
		
		cnt+=dfs(ny,nx);
	}
	return cnt;
}


void solve(){
	cin>>N>>M;
	memset(visited,-1,sizeof(visited));
	
	rep(i,0,M)
		rep(j,0,N){
			cin>>maps[i][j];
		}
		
	int roomCnt=0;
	int maxRoom=0;
	rep(i,0,M)
		rep(j,0,N)
			if(visited[i][j]==-1){
				roomCnt++;
				sv.push_back(dfs(i,j));
				maxRoom=max(maxRoom,sv.back());
				lnd++;			
			}
			
	adj.assign(roomCnt,set<int>());
	
	rep(y,0,M)
		rep(x,0,N)
			rep(i,0,4){
				int ny=y+dy[i];
				int nx=x+dx[i];
				
				if(ny<0||ny>=M||nx<0||nx>=N) continue;
				
				if(visited[y][x]!=visited[ny][nx])
					adj[visited[y][x]].insert(visited[ny][nx]);
			}
			
	int maxSize=0;
	rep(i,0,roomCnt){
		int size=sv[i];		
		
		for(auto it:adj[i]){
			maxSize=max(maxSize,size+sv[it]);
		}
	}
	cout<<roomCnt<<"\n";
	cout<<maxRoom<<"\n";
	cout<<maxSize;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
