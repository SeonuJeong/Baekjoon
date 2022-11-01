#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int A,B;
vector<int> a;
vector<int> b;
void solve(){
	cin>>A>>B;
	a.assign(A,0);
	b.assign(B,0);
	rep(i,0,A)
		cin>>a[i];
	
	rep(i,0,B)
		cin>>b[i];
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	int cnt=0;
	rep(i,0,A){
		int pos = (int)(lower_bound(b.begin(), b.end(), a[i])-b.begin());
		
		if(b[pos]==a[i]) continue;
		
		cnt++;
		
	}
	
	rep(i,0,B){
		int pos = (int)(lower_bound(a.begin(), a.end(), b[i])-a.begin());
		
		if(a[pos]==b[i]) continue;
		
		cnt++;
		
	}
	
	cout<<cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

solve();
}
