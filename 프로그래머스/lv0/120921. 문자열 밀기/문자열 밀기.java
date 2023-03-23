import java.util.*;
class Solution {
    public int solution(String A, String B) {
        int answer = 0;
        
        for(int i=0;i<B.length();i++){
            String subB = B.substring(i);
            int pos = A.indexOf(subB);
            if(pos==-1) continue;
            String subA = A.substring(pos+subB.length());
            
            if(B.equals(subA+subB)){
                answer=i;
                return answer;
            }
        }
        answer=-1;
        return answer;
    }
}