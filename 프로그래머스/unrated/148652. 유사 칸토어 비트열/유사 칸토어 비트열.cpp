#include <bits/stdc++.h>

using namespace std;

int getParent(int n, long long order){
    
    if(n==0)
        return 1;
    
    long long beforeOrder = order/5;
    
    int parent = getParent(n-1,beforeOrder);
    
    if(parent==0)
        return 0;
    
    long long subOrder = order%5;
    
    string str = "11011";
    
    return str[subOrder]-'0';
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    for(long long i=l-1;i<r;){
       
        if(i%5!=0||i-(r-1)<4){
            if(getParent(n,i))
                answer++;
            
            i++;
            continue;
        }
        
        long long beforeOrder = i/5;
        
        int parent = getParent(n-1,beforeOrder);
        
        if(parent)
            answer+=4;
        
        i+=5;
    }
    
    return answer;
}