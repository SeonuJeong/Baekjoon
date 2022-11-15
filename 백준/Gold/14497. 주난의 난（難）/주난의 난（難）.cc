#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int N,M,xl,yl,x2,y2;
char maps[301][301];
int visited[301][301];
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};

bool bfs(){
	queue<pi> que;
	que.push({xl,yl});
	visited[xl][yl]=1;
	
	while(!que.empty()){
		int y,x;
		tie(y,x)=que.front();que.pop();
		
		rep(i,0,4){
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(ny<0||ny>N||nx<0||nx>M) continue;
			if(visited[ny][nx]) continue;
			
			if(maps[ny][nx]=='1')
				maps[ny][nx]='0';
			else if(maps[ny][nx]=='0')
				que.push({ny,nx});
			
			visited[ny][nx]=1;
			
			if(ny==x2&&nx==y2)
				return true;
			
		}
	}
	return false;
}

void solve(){
	cin>>N>>M>>xl>>yl>>x2>>y2;
	memset(maps,0,sizeof(maps));
	memset(visited,0,sizeof(visited));
	
	rep(i,1,N+1){
		string s; cin>>s;
		rep(j,1,M+1){
			maps[i][j]=s[j-1];		
		}
	}
	int cnt=0;
	while(true){
		cnt++;
		if(bfs()){
			break;
		}
		memset(visited,0,sizeof(visited));
	}
	
	cout<<cnt;
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
