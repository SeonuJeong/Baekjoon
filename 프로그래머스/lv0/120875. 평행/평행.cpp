#include <bits/stdc++.h>

using namespace std;

bool isParaller(vector<vector<int>> a, vector<vector<int>> b){
    int diff_a_y = abs(a[0][1]-a[1][1]);
    int diff_a_x = abs(a[0][0]-a[1][0]);
    
    int diff_b_y = abs(b[0][1]-b[1][1]);
    int diff_b_x = abs(b[0][0]-b[1][0]);
    
    return diff_a_y*diff_b_x == diff_a_x*diff_b_y;
}

int solution(vector<vector<int>> dots) {
    
    vector<vector<int>> a;
    a.push_back(dots[0]);
    vector<vector<int>> b;
    
    for(int i=1;i<4;i++){
        a.push_back(dots[i]);
        for(int j=1;j<4;j++){
            if(i==j) continue;
            b.push_back(dots[j]);
        }
        
        if(isParaller(a,b)) return true;
        
        a.pop_back();
        b.clear();
    }
    
    return false;
}