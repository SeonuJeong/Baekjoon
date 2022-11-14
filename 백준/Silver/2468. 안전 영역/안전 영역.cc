#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;

int N;
int maps[100][100];
int visited[100][100];

int dy[] = {1,0,-1,0};
int dx[] = {0,-1,0,1};

void dfs(int y,int x,int h){
	
	visited[y][x]=1;
	
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		if(ny<0||ny>=N||nx<0||nx>=N||maps[ny][nx]<=h||visited[ny][nx])
			continue;
			
		dfs(ny,nx,h);
	}
}


void solve(){
	
	cin>>N;
	memset(maps,0,sizeof(maps));
	memset(visited,0,sizeof(visited));
	
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin>>maps[i][j];
	
	
	int maxCount=0;
	
	for(int h=0; h<=100;h++){
		int count=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(maps[i][j]>h&&!visited[i][j]){
					dfs(i,j,h);
					count++;
				}	
			}
		}
		
		memset(visited,0,sizeof(visited));
		maxCount=max(maxCount,count);
	}
	
	cout<<maxCount<<"\n";
}



int main() {

	ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

//	int t,i=1;
//	cin>>t;
//	while(t--){
//		//cout<<"Case #"<<i<<": ";
//		solve();
//		i++;
//	}
	solve();
}
