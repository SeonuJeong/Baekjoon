#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int n;
string s;
int fv[200001];
void solve(){
	cin>>n;
	cin>>s;
	memset(fv,0,sizeof(fv));
	
	vector<int> st;
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='(')
			st.push_back(i);
		else{
			if(!st.empty()){
				fv[i]=1;
				fv[st.back()]=1;
				st.pop_back();	
			}
		}	
	}
	
	int res=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		
		if(fv[i]==0) cnt=0;
		else{
			res = max(res,++cnt);
		}
	}
	
	cout<<res;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
