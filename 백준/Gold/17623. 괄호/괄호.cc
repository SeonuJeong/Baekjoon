#include <bits/stdc++.h>
#define sanic ios_base::sync_with_stdio(0);
#define MEM 1005
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const ll MOD = 10007;
ll n,t;
string dp[MEM];
string ml(string a, string b){
    if(a=="") return b;
    if(b=="") return a;
    if(a.size()<b.size()) return a;
    if(a.size()>b.size()) return b;
    ll f=a.size();
    for(int i=0; i<f; i++){
        if(a[i]<b[i]) return a;
        else if(b[i]<a[i]) return b;
    }
    return a;
}
string DP(ll n){
    string &ret = dp[n];
    if(ret!="") return ret;
    for(int i=1; i<n; i++)
        ret=ml(ret, DP(i)+DP(n-i));
    if(!(n%2))ret=ml(ret, "1"+DP(n/2)+"2");
    if(!(n%3))ret=ml(ret, "3"+DP(n/3)+"4");
    if(!(n%5))ret=ml(ret, "5"+DP(n/5)+"6");
    return ret;
}
int main(){
	sanic; cin.tie(0);
	cin >> t;
	dp[1] = "12";
    dp[2] = "34";
    dp[3] = "56";
	while(t--){
        cin >> n;
        DP(n);
        ll h=dp[n].size();
        for(int i=0; i<h; i++){
            if(dp[n][i]=='1')cout << '(';
            if(dp[n][i]=='2')cout << ')';
            if(dp[n][i]=='3')cout << '{';
            if(dp[n][i]=='4')cout << '}';
            if(dp[n][i]=='5')cout << '[';
            if(dp[n][i]=='6')cout << ']';
        }
        cout << '\n';
    }
}