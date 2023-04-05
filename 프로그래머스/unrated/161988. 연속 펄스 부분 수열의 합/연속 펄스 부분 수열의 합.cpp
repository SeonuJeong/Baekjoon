#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll INF  = 10e18;
ll dpR[500001];
ll dpC[500001];

int len;
vector<int> seq;

long long goR(int pos){
    if(pos==0)
        return seq[0];
    
    ll& ret = dpR[pos];
    
    if(ret!=-1*INF)
        return ret;
    
    ret = max((long long)seq[pos],goR(pos-1)+seq[pos]);
    return ret;
    
}

long long goC(int pos){
    
    if(pos==0){
        return seq[0];
    }
    
    ll& ret = dpC[pos];
    
    if(ret!=-1*INF)
        return ret;
    
    ret = max(goC(pos-1),max(goR(pos-1)+seq[pos],(long long)seq[pos]));
    return ret;
    
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    seq = sequence;
    len = sequence.size();
    
    fill(dpR,dpR+500001,-1*INF);
    fill(dpC,dpC+500001,-1*INF);
    for(int i=0,j=-1;i<len;i++){
        seq[i]*=j;
        j*=-1;
    }

    answer = goC(len-1);
    
  
    for(int i=0,j=-1;i<len;i++){
        seq[i]*=j;
    }
    fill(dpR,dpR+500001,-1*INF);
    fill(dpC,dpC+500001,-1*INF);
    return max(answer,goC(len-1));
    
    
}