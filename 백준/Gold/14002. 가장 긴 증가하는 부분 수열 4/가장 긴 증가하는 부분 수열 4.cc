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

void solve(){
	cin>>N;
	
	vector<int> ret;
	vector<pi> ans;	
	
	rep(i,0,N){
		int val;
		cin>>val;
		
		int pos=(int)(lower_bound(ret.begin(),ret.end(),val)-ret.begin());
		
		if(pos==ret.size())
			ret.push_back(val);
		else
			ret[pos]=val;
		
		ans.push_back({pos,val});
		
	}
	
	cout<<ret.size()<<"\n";
	
	int len=ret.size();
	vector<int> stk;
	for(int i=N-1;i>=0;i--){
		
		if(ans[i].f==len-1){
			stk.push_back(ans[i].s);
			len--;
		}
		
	}
	
	while(stk.size()){
		cout<<stk.back()<<" ";
		stk.pop_back();
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
