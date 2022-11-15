#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
//1012

int N;
int maps[10][10];
int visited[10][10];
int minMoney=INF;
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
vector<int> b;

void go(int idx,int cost){
	
	if(cost>=minMoney) return;
	
	if(idx==3){
		minMoney=min(minMoney,cost);
		return;
	}
	
	int y=b[idx]/N;
	int x=b[idx]%N;
	
	int tempCost=0;
	
	if(visited[y][x]){
		return;
	}
	tempCost=maps[y][x];
	visited[y][x]=1;
	
	rep(i,0,4){
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny<0||ny>=N||nx<0||nx>=N||visited[ny][nx]){
			tempCost-=INF; break;
		}
		visited[ny][nx]=1;
		tempCost+=maps[ny][nx];
	}
	
	if(tempCost<0) return;
	
	go(idx+1,cost+tempCost);
}


void combi(int start){
	if(b.size()==3){
		//todo
		go(0,0);
		memset(visited,0,sizeof(visited));
		return;
	}
	
	rep(i,start+1,N*N){
		b.push_back(i);
		combi(i);
		b.pop_back();
	}
}


void solve(){
	cin>>N;
	memset(maps,0,sizeof(maps));
	memset(visited,0,sizeof(visited));
	rep(i,0,N)
		rep(j,0,N)
			cin>>maps[i][j];
	
	combi(-1);
	
	cout<<minMoney;
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
