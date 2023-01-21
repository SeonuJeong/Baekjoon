#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;


void solve() {
	string s;
	cin>>s;
	
	queue<int> bq;
	queue<int> cq;
	int ret=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='A'&&bq.size()){
			ret++;
			bq.pop();
		}
		else if(s[i]=='B'){
			if(cq.size()){
				ret++;
				cq.pop();
			}
			else{
				bq.push(i);
			}
		}
		else if(s[i]=='C'){
			cq.push(i);
		}
	}
	
	cout<<ret;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
