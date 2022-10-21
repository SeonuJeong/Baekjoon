#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;
const int N=0;
const int S=1;
const int clw=1;
const int aclw=-1;

int t,k;
vector<vector<int>> v;
pi m[1001];

//go(pos-1,v[i][6],!dir,-1);
void go(int idx,int bfs,int c,int nxt){
	
	if(idx<0||idx>=t)
		return;
	
	if(nxt==-1&&(v[idx][2]==bfs)) return;
	else if(nxt==1&&(v[idx][6]==bfs)) return;
	
	int cs;
	
	if(nxt==-1) cs=v[idx][6];
	else cs = v[idx][2];
	
	go(idx+nxt,cs,-1*c,nxt);
	
	if(c==clw)
		rotate(v[idx].begin(),v[idx].begin()+v[idx].size()-1,v[idx].end());
	else if(c==aclw)
		rotate(v[idx].begin(),v[idx].begin()+1,v[idx].end());
	
}
void solve(){
	cin>>t;
	v.assign(t,vector<int>(8,0));
	
	rep(i,0,t){
		
		string s;cin>>s;
		
		rep(j,0,s.length())
			v[i][j]=s[j]-'0';

	}
	
//	rep(i,0,t){
//		rep(j,0,8){
//			cout<<v[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	cin>>k;
	rep(i,0,k){
		int pos,dir;cin>>pos>>dir;
		m[i]={--pos,dir};
	}
	
	rep(i,0,k){
		//자기 돌리고 전파 
		int pos, dir; tie(pos,dir)=m[i];
		
		//left
		go(pos-1,v[pos][6],-1*dir,-1);
		
		//right
		go(pos+1,v[pos][2],-1*dir,1);
		
		if(dir==clw)
			rotate(v[pos].begin(),v[pos].begin()+7,v[pos].end());
		else if(dir==aclw)
			rotate(v[pos].begin(),v[pos].begin()+1,v[pos].end());
		
	}
	
	//12시 확인 
	int ret=0;
	rep(i,0,t){
		if(v[i][0]==S) ret++;
	}
	cout<<ret;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
