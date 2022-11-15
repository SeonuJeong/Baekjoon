#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
//0930
int R,C,K;
char maps[5][5];
int visited[5][5];
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int dfs(int y,int x,int k){
	
	if(y==0&&x==C-1){
		if(k==K) return 1;
		else return 0;
	}
	
	if(k>=K) return 0;
	
	visited[y][x]=1;
	int cnt=0;
	rep(i,0,4){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||ny>=R||nx<0||nx>=C) continue;
		if(visited[ny][nx]) continue;
		if(maps[ny][nx]=='T')continue;
		cnt+=dfs(ny,nx,k+1);
	}
	
	visited[y][x]=0;
	return cnt;
}

void solve(){
	cin>>R>>C>>K;
	memset(maps,0,sizeof(maps));
	memset(visited,0,sizeof(visited));
	rep(i,0,R)
		rep(j,0,C)
			cin>>maps[i][j];
	
	cout<<dfs(R-1,0,1);
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
