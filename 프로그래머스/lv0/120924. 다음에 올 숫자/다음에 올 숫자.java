import java.util.*;

class Solution {
    public int solution(int[] common) {
        int answer = 0;
        
        
        int diff=common[1]-common[0];
        boolean flag=true;
        for(int i=2;i<common.length;i++){
            if(common[i]-common[i-1]!=diff)
                flag=false;
        }
        
        if(flag)
            answer = common[common.length-1]+diff;
        else{
            diff=common[1]/common[0];
            answer = common[common.length-1]*diff; 
        }
        
        
        return answer;
    }
}