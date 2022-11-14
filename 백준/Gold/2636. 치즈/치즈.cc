#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int maps[100][100];
int visited[100][100];
int N,M;
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};

void dfs(int y,int x){
	visited[y][x]=1;
	
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||ny>=N||nx<0||nx>=M||visited[ny][nx]!=0) continue;
		if(maps[ny][nx]==1){
			visited[ny][nx]=2;continue;
		}
		
		dfs(ny,nx);
	}
}


void solve(){
	
	memset(maps,0,sizeof(maps));
	memset(visited,0,sizeof(visited));
	
	cin>>N>>M;
	int total=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			cin>>maps[i][j];
			if(maps[i][j])total++;
		}
			
	int time=0;
	int before=0;
	while(total){
		int remove=0;
		dfs(0,0);
		
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++){
				if(visited[i][j]==2){
					remove++; maps[i][j]=0;
				}
			}
		time++;
		
		if(total-remove==0){
			before = total;
		}
		total-=remove;
		
		memset(visited,0,sizeof(visited));
	}
	
	cout<<time<<"\n";
	cout<<before;
	
}



int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

solve();
}
