#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;
char maps[100][100];
int result[100][100];
void solve(){
	
	memset(maps,0,sizeof(maps));
	memset(result,0,sizeof(result));
	
	int H,W;
	cin>>H>>W;
	
	string s;
	for(int i=0; i<H;i++){
		cin>>s;
		for(int j=0; j<W;j++){
			maps[i][j]=s[j];
		}
	}
	
	for(int i=0; i<H;i++){
		int cloud=-1;
		for(int j=0;j<W;j++){
			if(maps[i][j]=='c')
				cloud=0;
			result[i][j]=cloud;
			
			if(cloud!=-1) cloud++;
		}
	}
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cout<<result[i][j]<<" ";		
		}
		cout<<"\n";
	}
			
}



int main() {

	ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
