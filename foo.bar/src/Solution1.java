public class Solution1 {
    private static char[] reverseMapping = new char[]{'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    public static String solution(String x) {
        StringBuilder decodeString = new StringBuilder();
        for (int i = 0; i < x.length(); ++i) {
            if (x.charAt(i) >= 'a' && x.charAt(i) <= 'z')
                decodeString.append(reverseMapping[x.charAt(i) - 'a']);
            else
                decodeString.append(x.charAt(i));
        }
        return decodeString.toString();
    }
}
