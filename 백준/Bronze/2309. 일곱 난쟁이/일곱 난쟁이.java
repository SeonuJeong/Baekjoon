import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> list = new ArrayList<>();

        int sum=0;
        for(int i=0;i<9;i++){
            int tmp=sc.nextInt();
            list.add(tmp);
            sum+=tmp;
        }

        ArrayList<Integer> results= new ArrayList<>();
        boolean finish= false;
        for(int i=0;i<list.size();i++){
            for(int j=i+1;j<list.size();j++){
                if(sum-(list.get(i)+ list.get(j))==100){
                    for(int k=0;k<list.size();k++){
                        if(k==i||k==j) continue;

                        results.add(list.get(k));
                    }
                    finish=true;
                    break;
                }
            }

            if(finish) break;
        }

        Collections.sort(results);

        for(int v: results){
            System.out.println(v);
        }

    }
}