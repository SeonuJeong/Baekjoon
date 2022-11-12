#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int N;
string front="",back="";
void solve(){
	cin>>N;
	string tmp;cin>>tmp;
	
	bool flag=true;
	rep(i,0,tmp.size()){
		
		if(tmp[i]=='*'){
			flag=false;
			continue;
		}
		
		if(flag)
			front+=tmp[i];
		else
			back+=tmp[i];
	}
	
	rep(i,0,N){
		string s;cin>>s;
		//cout<<s.substr(s.size()-back.size(),back.size())<<"\n";
		if(s.size()<(front.size()+back.size())){
			cout<<"NE\n";
			continue;
		}
		
		if(s.substr(0,front.size())==front&&s.substr(s.size()-back.size(),back.size())==back)
			cout<<"DA\n";
		else
			cout<<"NE\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
