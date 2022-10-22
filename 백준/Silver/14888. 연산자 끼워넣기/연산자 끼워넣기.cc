#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

const int PLUS=-2;
const int MINUS=-1;
const int MUL=0;
const int DIV=1;

int n;
int a[12];
vector<int> op;
vector<int> p;


int go(){
	
	int lv=a[0];
	
	rep(i,1,n){
		int rv=a[i];
		
		int vle = op[p[i-1]];
		
		if(vle==PLUS) lv = lv+rv;
		else if(vle==MINUS) lv=lv-rv;
		else if(vle==MUL) lv=lv*rv;
		else if(vle==DIV) lv = lv>0?lv/rv:-(abs(lv)/rv);
	
	}
	
	return lv;
}

void solve(){
	cin>>n;
	
	rep(i,0,n)
		cin>>a[i];
	
	
	int tmp=PLUS;
	int totalCnt=0;
	rep(i,0,4){
		int cnt;cin>>cnt;
		rep(j,0,cnt){
			op.push_back(tmp);
			totalCnt++;
		}	
		tmp++;
	}
	
	rep(i,0,totalCnt){
		p.push_back(i);
	}
	
	int retM=-INF;
	int retN=INF;
	
	do{
		int rtn=go();	
		retM=max(retM,rtn);
		retN=min(retN,rtn);
	}while(next_permutation(p.begin(),p.end()));

	cout<<retM<<"\n"<<retN;	
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
}
