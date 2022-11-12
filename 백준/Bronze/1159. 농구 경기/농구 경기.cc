#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int a[27];
void solve(){
	int n;cin>>n;
	
	bool flag=true;
	rep(i,0,n){
		string s;cin>>s;
		a[s[0]-'a']++;
		
		if(a[s[0]-'a']==5)
			flag=false;
	}
	
	if(flag){
		cout<<"PREDAJA";
		return;
	}
		
	
	rep(i,0,26){
		if(a[i]>=5)
			cout<<(char)('a'+(char)i);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
