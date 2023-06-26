import java.util.*;
import java.io.*;

class Solution {
    public List<Integer> solution(long n) {
        
        List<Integer> answer = new ArrayList<>();
        
        while(n!=0){
            answer.add((int)(n%10L));
            n=n/10;
        }

        return answer;
    }
}