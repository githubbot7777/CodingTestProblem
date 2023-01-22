import java.util.*;

//https://www.acmicpc.net/problem/2437
/* 추 3개 있을경우
 * arr=[1,2,3]
 * 1~6까지 만들수있다 
 * 1
 * 2
 * 3
 * 4=1+3
 * 5=2+3
 * 6=1+2+3
 * 다음으로 5가 들어오면
 * 7,8,9,10,11 만들수있다.
 * 하지만 8이 들어올경우 7을 만들지 못한다
 * 
 * 이전 상태까지 만들 수 있는 무게 W가 있을 때,
   이 무게 W + 1이 그 다음 무게추보다 크거나 같다면
   계속 이 무게를 쌓아나갈 수 있다. 
 */
public class Main {

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int t = sc.nextInt();
            list.add(t);
        }
        Collections.sort(list);
        int sum = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) > sum + 1)
                break;
            else
                sum += list.get(i);
        }

        System.out.print(sum + 1);

    }
}
