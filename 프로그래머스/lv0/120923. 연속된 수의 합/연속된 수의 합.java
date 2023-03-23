import java.util.*;
class Solution {
    public int[] solution(int num, int total) {
        int[] answer = {};
        List<Integer> ans = new ArrayList<>();
        
        int start = ((total*2/num)+1-num)/2;
        
        for(int i=0;i<num;i++){
            ans.add(start+i);
        }
        
        answer = ans.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
        
    }
}