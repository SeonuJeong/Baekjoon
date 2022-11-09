#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int,int,int> ti;
const int INF = 1e9;

double A,B;

double dp[91][20][20];

bool isPrime(int n){
	bool flag=true;
	
	if(n==1||n==0)
		return false;
	
	for(int i=2;i<n;i++){
		if(n%i==0) flag=false;
	}
	return flag;
}


double go(int time,int a,int b){
	
	if(time==90){
		if(isPrime(a)||isPrime(b))
			return 1.0;
		else 
			return 0.0;
	}
	
	double& ret= dp[time][a][b];
	
	if(ret>-0.5)
		return ret;

	double val=0;
	val+=go(time+5,a+1,b)*A*(1-B);
	val+=go(time+5,a,b+1)*(1-A)*(B);
	val+=go(time+5,a+1,b+1)*(A)*(B);
	val+=go(time+5,a,b)*(1-A)*(1-B);
	
	ret=val;
	return val;
}


void solve(){
	scanf("%lf %lf", &A, &B); 
	A=A/100;
	B=B/100;

	memset(dp, -1, sizeof(dp)); 
	printf("%.6lf", go(0, 0, 0));
}

int main() {

	solve();
	
}
