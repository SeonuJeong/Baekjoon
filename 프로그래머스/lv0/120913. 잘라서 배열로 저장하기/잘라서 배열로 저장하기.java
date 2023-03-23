import java.util.*;
class Solution {
    public String[] solution(String my_str, int n) {
        int len=my_str.length();
        String[] answer = new String[(len%n)==0?len/n:len/n+1];
        Arrays.fill(answer,"");
        for(int i=0;i<len;i++){
            answer[i/n]+=my_str.charAt(i);
        }
        
        return answer;
    }
}