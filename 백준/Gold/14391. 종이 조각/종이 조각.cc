#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
//0835
int M,N;
char maps[4][4];
int idn[4][4];
int visited[4][4];
int maxRet=0;



int go(int y,int x){
	int dy=0,dx=0;
	if(idn[y][x]==0) dy=1;
	else dx=1;
	
	string sum ="";
	sum+=maps[y][x];
	
	while(true){
		int ny = y+dy;
		int nx = x+dx;
		
		if(ny<0||ny>=M||nx<0||nx>=N) break;
		if(idn[ny][nx]!=idn[y][x]) break;
		if(visited[ny][nx]) break;
		
		visited[ny][nx]=1;
		sum+=maps[ny][nx];
		y+=dy; x+=dx;
	}
	
	return stoi(sum);
}

void dfs(int y,int x){
	
	if(x>=N){
		y+=1;
		x=0;
	}	
	
	if(y>=M){
		int sum=0;
		memset(visited,0,sizeof(visited));
		rep(i,0,M)
			rep(j,0,N)
				if(!visited[i][j]){
					sum+=go(i,j);
				}
		maxRet=max(maxRet,sum);
		return;
	}
	
	dfs(y,x+1);
	
	idn[y][x]=1;
	dfs(y,x+1);
	idn[y][x]=0;
}

void solve(){
	cin>>M>>N;
	
	memset(idn,0,sizeof(idn));
	rep(i,0,M)
		rep(j,0,N)
			cin>>maps[i][j];
	dfs(0,0);
	
	cout<<maxRet;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
