#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(int i=x;i<n;i++)
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pi;

const int INF = 1e9;

ll N;
ll v[500001];
void solve(){
	cin>>N;
	memset(v,0,sizeof(v));
	
	rep(i,0,N)
		cin>>v[i];
	
	vector<pi> st;
	st.push_back({v[0],1});
	
	ll res=0;
	
	rep(i,1,N){
		
		if(v[i]<st.back().f){
			res++;
			st.push_back({v[i],1});
		}
		else if(v[i]==st.back().f){
			res+=st.back().s;
			
			if(st.size()>=2)
				res++;
			
			st.back().s++;
		}
		else{
		
			while(!st.empty()&&st.back().f<v[i]){ 
				res+=st.back().s;
				st.pop_back();
			}
			
			if(st.empty()){
				st.push_back({v[i],1});
			}
			else{
				if(st.back().f==v[i]){		
					res+=st.back().s;
					if(st.size()>=2)
						res++;
						
					st.back().s++;
				}
				else{
					res++;
					st.push_back({v[i],1});
				}
			}
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
