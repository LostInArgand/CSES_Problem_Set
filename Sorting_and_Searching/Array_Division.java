import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Array_Division {

    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        int n = fs.nextInt();
        int k = fs.nextInt();
        ArrayList<Long> arr = new ArrayList<Long>();
        for (int i = 0; i < n; i++) arr.add(fs.nextLong());

        // Binary Search
        long l = Collections.max(arr);
        long r = 1000000000000000000L;
        long mid = (l + r) / 2;
        long ans = 1000000000000000000L;
        while(l <= r){
            mid = (l + r) / 2;
            if (check(arr, mid, n, k)){
                r = mid - 1;
                ans = Math.min(ans, mid);
            }
            else l = mid + 1;
        }
        System.out.println(ans);
    }

    static boolean check(ArrayList<Long> arr, long max, int n, int k){
        int count = 1;
        long sum = 0;
        for (int i = 0; i < n; i++){
            if(sum + arr.get(i) > max){
                sum = arr.get(i);
                count += 1;
            }
            else sum += arr.get(i);
        }
        return count <= k;
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
