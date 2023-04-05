#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]>b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    int wanhoSum = scores[0][0]+scores[0][1];
    int wa = scores[0][0];
    int wb = scores[0][1];
    
    sort(scores.begin(), scores.end(), cmp);
    
    vector<int> sums;
    
    int maxb=0;
    
    for(vector<int> v: scores){
        if(maxb>v[1]){
            if(v[0]==wa && v[1]==wb)
                return -1;
            continue;
        }
        
        maxb=max(maxb,v[1]);
        sums.push_back(v[0]+v[1]);
    }
    
    
    sort(sums.begin(), sums.end(), greater<int>());
    
    int rank=1;
    int stack=1;
    for(int i=0;i<sums.size();i++){
        
        if(i!=0&&sums[i-1]==sums[i]){
            stack++;
        }
        else if(i!=0&&sums[i-1]!=sums[i]){
            rank+=stack;
            stack=1;
        }
        
        if(wanhoSum == sums[i]){
            answer=rank;
            break;
        }
            
    }
    return answer;
}