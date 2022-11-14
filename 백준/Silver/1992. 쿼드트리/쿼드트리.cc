#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;
int N;
char maps[101][101];
int dy[] = {0,0,1,1};
int dx[] = {0,1,0,1};

string dfs(int y,int x,int n){
	
	if(n==1){
		return string(1, maps[y][x]);
	}
	
	bool out=false;
	for(int i=y; i<y+n;i++){
		for(int j=x; j<x+n;j++){
			if(maps[y][x]!=maps[i][j])
				out=true;
		}
	}
	
	if(!out) return string(1, maps[y][x]);
	

	string s="";
	s+='(';
	for(int i=0; i<4; i++){
		int ny = y+dy[i]*(n/2);
		int nx = x+dx[i]*(n/2);
		
		s+= dfs(ny,nx,n/2);
	}
	s+=')';
	
	return s;
}

void solve(){

	memset(maps,0,sizeof(maps));
	cin >> N;
	 
	string s;
    for(int i = 0; i < N; i++){
        cin >> s; 
        for(int j = 0; j < N; j++){
            maps[i][j] = s[j];
        }
    }
	
	cout<<dfs(0,0,N);
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
