#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

int n;


void solve(){
	ll x = 1;
	int cnt = 1;
	
	while(x%n){
		x = ((x*10)%n+1)%n;
		cnt++;
	}	
	
	cout<<cnt<<"\n";
}

int main() {	
	while(cin>>n){
		solve();
	}
}
