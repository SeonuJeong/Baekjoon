#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

ll vals[10];
char ops[10];
int N;
ll ret=-INF;

ll cal(ll a,ll b,char op){
	
	if(op=='+')
		return a+b;
	
	if(op=='-')
		return a-b;
		
	if(op=='*')
		return a*b;
	
}

void go(ll sum,int pos){
	//cout<<sum<<"pos: "<<pos<<"\n";
	if(pos>((N-1)/2)){
		ret=max(sum,ret);
		return;
	}
	
	if((pos+1)<=((N-1)/2))
		go(cal(sum,cal(vals[pos],vals[pos+1],ops[pos]),ops[pos-1]),pos+2);
	
	go(cal(sum,vals[pos],ops[pos-1]),pos+1);	
}


void solve(){
	cin>>N;
	string s;cin>>s;
	rep(i,0,N){
		if(i%2==0)
			vals[i/2]=s[i]-'0';
		else
			ops[(i-1)/2]=s[i];
	}
	//cout<<ops[1];
	go(vals[0],1);
	cout<<ret;
	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
