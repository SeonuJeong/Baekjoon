#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;
int dt[10]={6,2,5,5,4,5,6,3,7,6};
string dp[101];
string dp2[101];

int compare(string ret,string s){
	
	if(s.size()>ret.size())
		return 1;
	else if(s.size()<ret.size())
		return 0;
		
	rep(i,0,s.size()){
		if(s[i]>ret[i]) return 1;
		else if(s[i]<ret[i]) return 0;
	}
	
	return 1;
}

int compare2(string ret,string s){

			
	if(s.size()<ret.size())
		return 1;
	else if(s.size()>ret.size())
		return 0;
		
	rep(i,0,s.size()){
		if(s[i]<ret[i]) return 1;
		else if(s[i]>ret[i]) return 0;
	}
	
	return 1;
}

string go(int n){
	
	
	if(n==0){
		return "";
	}
	
	if(!(dp[n]=="-2"))
		return dp[n];
	
	
	string ret="-1";

	rep(i,0,10){
		if(n-dt[i]<0) continue;
		
		string tmp =go(n-dt[i]);
		
		if(tmp=="-1") continue; 
		
		tmp=(char)('0'+i)+tmp;
		
		if(ret=="-1"||compare(ret,tmp))
			ret=tmp;
	}
	
	dp[n]=ret;
	return ret;
}

string go2(int n){
	
	
	
	if(n==0){
		return "";
	}
	//cout<<"n: "<<n<<" dp2:"<<dp2[n]<<"\n";
	if(!(dp2[n]=="-2"))
		return dp2[n];
	
		
	
	string ret="-1";

	rep(i,0,10){
		if(n-dt[i]<0) continue;
		
		string tmp =go2(n-dt[i]);
		
		if(tmp=="-1") continue; 
		
		tmp=(char)('0'+i)+tmp;
		
		if(ret=="-1"||compare2(ret,tmp))
			ret=tmp;
	}
	
	dp2[n]=ret;
	return ret;
}

void solve(){
	int N;cin>>N;
	
	rep(i,0,101){
		dp[i]= "-2";
		dp2[i]="-2";
	}
	
	string ret="-1";
	
	rep(i,1,10){
		if(N-dt[i]<0) continue;
		
		string tmp=go2(N-dt[i]);
		
		if(tmp=="-1") continue;
		
		tmp=(char)('0'+i)+tmp;
		
		if(ret=="-1"||compare2(ret,tmp))
			ret=tmp;
	}
	
	cout<<ret<<" ";
	
	
	ret="-1";
	rep(i,1,10){
		if(N-dt[i]<0) continue;
		string tmp=go(N-dt[i]);
		
		if(tmp=="-1") continue;
		
		tmp=(char)('0'+i)+tmp;
		
		if(ret=="-1"||compare(ret,tmp))
			ret=tmp;
	}
	
	cout<<ret<<"\n";
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	int t;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}
