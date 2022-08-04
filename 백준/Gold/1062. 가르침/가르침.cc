#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;
//0113
int N,K;
int w[50];
int maxValue=0;

int count(int mask) {
    int cnt = 0;
    for (int word : w) { 
        if(word && (word & mask) == word)cnt++; 
    }
    return cnt;
}

void dfs(int idx,int k,int state){
	
	if(k<0) return;
	
	if(idx==26){
		maxValue=max(maxValue,count(state));
		return;
	}
	
	if(idx=='a'-'a'||idx=='n'-'a'||idx=='t'-'a'||idx=='i'-'a'||idx=='c'-'a')
		dfs(idx+1,k-1,state|(1<<idx));
	else{
		dfs(idx+1,k-1,state|(1<<idx));
		dfs(idx+1,k,state);
	}
}

int toBit(string s){
	int rst=0;
	rep(i,0,s.length()){
		rst = rst|(1<<(s[i]-'a'));
	}
	return rst;
}

void solve(){
	cin>>N>>K;
	memset(w,0,sizeof(w));
	
	
	rep(i,0,N){
		string s;cin>>s;
		w[i]=toBit(s);
	}
	
	if(K-5<0){
		cout<<0;return;
	}
	dfs(0,K,0);
	cout<<maxValue;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
