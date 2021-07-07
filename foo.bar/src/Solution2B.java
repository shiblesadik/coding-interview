import java.util.LinkedList;
import java.util.Queue;

/*
Don't Get Volunteered!
======================

As a henchman on Commander Lambda's space station, you're expected to be resourceful, smart, and a quick thinker.
It's not easy building a doomsday device and ordering the bunnies around at the same time,
after all! In order to make sure that everyone is sufficiently quick-witted,
Commander Lambda has installed new flooring outside the henchman dormitories.
It looks like a chessboard, and every morning and evening you have to solve a new movement puzzle in order to cross the floor.
That would be fine if you got to be the rook or the queen, but instead, you have to be the knight.
Worse, if you take too much time solving the puzzle, you get "volunteered" as a test subject for the LAMBCHOP doomsday device!

To help yourself get to and from your bunk every day,
write a function called solution(src, dest) which takes in two parameters:
the source square, on which you start, and the destination square, which is where you need to land to solve the puzzle.
The function should return an integer representing the smallest number of moves it will take for you to travel from the
source square to the destination square using a chess knight's moves
(that is, two squares in any direction immediately followed by one square perpendicular to that direction, or vice versa, in an "L" shape).
  Both the source and destination squares will be an integer between 0 and 63, inclusive, and are numbered like the example chessboard below:

-------------------------
| 0| 1| 2| 3| 4| 5| 6| 7|
-------------------------
| 8| 9|10|11|12|13|14|15|
-------------------------
|16|17|18|19|20|21|22|23|
-------------------------
|24|25|26|27|28|29|30|31|
-------------------------
|32|33|34|35|36|37|38|39|
-------------------------
|40|41|42|43|44|45|46|47|
-------------------------
|48|49|50|51|52|53|54|55|
-------------------------
|56|57|58|59|60|61|62|63|
-------------------------

Languages
=========

To provide a Python solution, edit solution.py
To provide a Java solution, edit Solution.java

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases --
Input:
Solution.solution(19, 36)
Output:
    1

Input:
Solution.solution(0, 1)
Output:
    3
*/
public class Solution2B {
    public static int solution(int src, int dest) {
        int[][] ans = new int[8][8];
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                ans[i][j] = 499999999;
            }
        }
        Queue<Grid> queue = new LinkedList<Grid>();
        int x = src / 8;
        int y = src % 8;
        queue.add(new Grid(x, y));
        ans[x][y] = 0;

        while (!queue.isEmpty()) {
            x = queue.peek().x;
            y = queue.peek().y;
            int val = (x * 8) + (y % 8);
            if (val == dest) {
                return ans[x][y];
            }
            queue.remove();

            if (x - 2 >= 0 && y - 1 >= 0 && ans[x - 2][y - 1] > ans[x][y]) {
                queue.add(new Grid(x - 2, y - 1));
                ans[x - 2][y - 1] = ans[x][y] + 1;
            }
            if (x - 2 >= 0 && y + 1 <= 7 && ans[x - 2][y + 1] > ans[x][y]) {
                queue.add(new Grid(x - 2, y + 1));
                ans[x - 2][y + 1] = ans[x][y] + 1;
            }
            if (x + 2 <= 7 && y - 1 >= 0 && ans[x + 2][y - 1] > ans[x][y]) {
                queue.add(new Grid(x + 2, y - 1));
                ans[x + 2][y - 1] = ans[x][y] + 1;
            }
            if (x + 2 <= 7 && y + 1 <= 7 && ans[x + 2][y + 1] > ans[x][y]) {
                queue.add(new Grid(x + 2, y + 1));
                ans[x + 2][y + 1] = ans[x][y] + 1;
            }

            if (x - 1 >= 0 && y - 2 >= 0 && ans[x - 1][y - 2] > ans[x][y]) {
                queue.add(new Grid(x - 1, y - 2));
                ans[x - 1][y - 2] = ans[x][y] + 1;
            }
            if (x - 1 >= 0 && y + 2 <= 7 && ans[x - 1][y + 2] > ans[x][y]) {
                queue.add(new Grid(x - 1, y + 2));
                ans[x - 1][y + 2] = ans[x][y] + 1;
            }
            if (x + 1 <= 7 && y - 2 >= 0 && ans[x + 1][y - 2] > ans[x][y]) {
                queue.add(new Grid(x + 1, y - 2));
                ans[x + 1][y - 2] = ans[x][y] + 1;
            }
            if (x + 1 <= 7 && y + 2 <= 7 && ans[x + 1][y + 2] > ans[x][y]) {
                queue.add(new Grid(x + 1, y + 2));
                ans[x + 1][y + 2] = ans[x][y] + 1;
            }
        }
        return ans[dest / 8][dest % 8];
    }

    private static class Grid {
        int x;
        int y;

        Grid(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}