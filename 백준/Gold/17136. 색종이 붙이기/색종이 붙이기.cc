#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int N=10;
int maps[10][10];
int box[6]={0,5,5,5,5,5};
int visited[10][10];
int minBox=INF;

bool checkBox(int y,int x,int l){
	if(y+l>N||x+l>N) return false;
	for(int i=y;i<y+l;i++)
		for(int j=x;j<x+l;j++)
			if(maps[i][j]==0)
				return false;
	return true;
}

void stateChange(int y,int x,int l,int v){
	for(int i=y; i<y+l; i++)
		for(int j=x; j<x+l; j++)
			maps[i][j]=v;
}

void dfs(int y,int x,int cur){
	
	if(cur>=minBox) return;
	
	if(y==N){
		minBox=min(minBox,cur);
		return ;
	}
	
	if(x==N){
		dfs(y+1,0,cur);
		return;
	}
	
	if(maps[y][x]==0/*||visited[y][x]*/){
		dfs(y,x+1,cur);
		return;
	}
	
	//maps[y][x]==1
	for(int i=5;i>=1;i--){
		
		if(box[i]==0) continue;
		
		if(!checkBox(y,x,i)) continue;
		
		stateChange(y,x,i,0);
		box[i]--;
		
		dfs(y,x+i,cur+1);
		
		box[i]++;
		stateChange(y,x,i,1);
	}	
}


void solve(){
	memset(maps,0,sizeof(maps));
	memset(visited,0,sizeof(visited));
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>maps[i][j];
			
		}
			
	
	dfs(0,0,0);
	cout<<(minBox==INF?-1:minBox);
}



int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
