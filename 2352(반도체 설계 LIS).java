
import java.util.*;

//https://www.acmicpc.net/problem/2352
/* 
 LIS(Longest Increasign Subsequence) 문제
 설명
 https://9327144.tistory.com/entry/%EC%B5%9C%EC%9E%A5-%EC%A6%9D%EA%B0%80-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4LIS-Longest-Increasing-Subsequence?category=945533
 https://9327144.tistory.com/entry/BOJ-2352-%EB%B0%98%EB%8F%84%EC%B2%B4-%EC%84%A4%EA%B3%84C
 강의영상
 https://www.youtube.com/watch?v=sYh62pujaH8

 */
public class Main {
    static final int MAX = 40002;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[MAX];
        int[] dp = new int[MAX];
        Arrays.fill(arr, 0);
        Arrays.fill(dp, 0);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++)
            arr[i + 1] = sc.nextInt();

        dp[1] = arr[1];
        int maxlast = 1;
        for (int i = 1; i <= n; i++) {
            int l = 1;
            int r = maxlast;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (arr[i] == dp[mid]) {
                    l = mid;
                    break;
                } else if (arr[i] < dp[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            dp[l] = arr[i];
            maxlast = Math.max(maxlast, l);
        }
        System.out.print(maxlast);
    }
}
