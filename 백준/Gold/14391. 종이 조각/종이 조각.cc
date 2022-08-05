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
int visited[4][4];
int maxRet=0;
int k;


int go(int y,int x){
	int dy=0,dx=0;
	if(k&(1<<(N*y+x))) dx=1;
	else dy=1;
	
	string sum ="";
	sum+=maps[y][x];
	
	while(true){
		int ny = y+dy;
		int nx = x+dx;
		
		if(ny<0||ny>=M||nx<0||nx>=N) break;
		bool A = (k&(1<<(N*y+x)));
		bool B = (k&(1<<(N*ny+nx)));
		if((A^B)==1) break;
		if(visited[ny][nx]) break;
		
		visited[ny][nx]=1;
		sum+=maps[ny][nx];
		y+=dy; x+=dx;
	}
	
	return stoi(sum);
}


void solve(){
	cin>>M>>N;
	

	rep(i,0,M)
		rep(j,0,N)
			cin>>maps[i][j];
			
			
	for(k=0;k<(1<<(M*N));k++){
		
		int sum=0;
		memset(visited,0,sizeof(visited));
		rep(i,0,M)
			rep(j,0,N)
				if(!visited[i][j]){
					sum+=go(i,j);
				}
		maxRet=max(maxRet,sum);
	}		
			
	
	cout<<maxRet;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
