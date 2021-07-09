public class Main {

    public static void main(String[] args) {
//        for (int i = 1; i <= 100; ++i) {
//            for (int j = i + 1; j <= 100; ++j) {
//                System.out.println(i + " " + j + " " + Solution.solution(Integer.toString(i), Integer.toString(j)));
//            }
//        }
        System.out.println(Solution.solution("1", "1"));
        System.out.println(Solution.solution("0", "0"));
        System.out.println(Solution.solution("0", "1"));
        System.out.println(Solution.solution("0", "2"));
        System.out.println(Solution.solution("104", "17"));
        System.out.println(Solution.solution("10000000000000000000000000000000000000001", "100000000000000000000000000000000000000000000000000"));
    }
}
