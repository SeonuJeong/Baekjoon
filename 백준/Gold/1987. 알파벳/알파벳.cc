#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
//0226
int R,C;
char maps[20][20];
int visited[30];

int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};


int dfs(int y,int x,int result){
	
	visited[maps[y][x]-'A']=1;
	
	int maxValue=result;
	
	rep(i,0,4){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||ny>=R||nx<0||nx>=C) continue;
		if(visited[maps[ny][nx]-'A']) continue;
		
		visited[maps[ny][nx]-'A']=1;
		maxValue = max(maxValue,dfs(ny,nx,result+1));
		visited[maps[ny][nx]-'A']=0;
	}
	
	return maxValue;
}


void solve(){
	cin>>R>>C;
	memset(maps,0,sizeof(maps));
	memset(visited,0,sizeof(visited));
	
	rep(i,0,R)
		rep(j,0,C)
			cin>>maps[i][j];
	
	cout<<dfs(0,0,1);
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
