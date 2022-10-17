#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int n;
vector<int> primeNum;
vector<int> p;
void isPrime(int n){
	
	for(int i=2;i<=n;i++){
		primeNum[i]=i;
	}
	
	for(int i=2;i<=sqrt(n);i++){
		
		if(primeNum[i]==0)
			continue;
		
		for(int j=i*i;j<=n;j+=i)
			primeNum[j]=0;
	}
	
	for(int i=2;i<=n;i++){
		if(primeNum[i]!=0)
			p.push_back(i);
	}	
}

void solve(){
	cin>>n;
	primeNum.assign(n+1,0);
	
	isPrime(n);
	
	int le=0,ri=0;
	int sum=0;
	int count=0;

	
	while(1){
		if(sum>=n) sum-=p[le++];
		else if(ri==p.size())break;
		else sum+=p[ri++];
		
		if(sum==n) count++;
	}
	

	cout<<count;
}

int main() {

	ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	solve();
	
	return 0;
}
