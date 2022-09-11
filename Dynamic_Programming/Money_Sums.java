import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class Money_Sums {

    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        int n = fs.nextInt();
        int val;
        int[] mem = new int[100010];
        Arrays.fill(mem, 0);
        for(int i = 0; i < n; i++){
            val = fs.nextInt();
            for(int j=100000; j > 0; j--){
                if (mem[j] == 1 && j+val <= 100000) mem[j + val] = 1;
            }
            mem[val] = 1;
        }
        int sum = IntStream.of(mem).sum();
        System.out.println(sum);
        for (int i=0; i<=100000; i++){
            if(mem[i]==1){
                System.out.print(i);
                System.out.print(" ");
            }
        }
    }

//    static void sort(int[] a) {
//        ArrayList<Integer> l=new ArrayList<>();
//        for (int i:a) l.add(i);
//        Collections.sort(l);
//        for (int i=0; i<a.length; i++) a[i]=l.get(i);
//    }

    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }


}
