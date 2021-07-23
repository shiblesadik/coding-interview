/*
Prepare the Bunnies' Escape
===========================

You're awfully close to destroying the LAMBCHOP doomsday device and freeing Commander Lambda's bunny workers,
but once they're free of the work duties the bunnies are going to need to escape Lambda's space station via the escape pods as quickly as possible.
Unfortunately, the halls of the space station are a maze of corridors and dead ends that will be a deathtrap for the escaping bunnies.
Fortunately, Commander Lambda has put you in charge of a remodeling project that will give you the opportunity to make things a little easier for the bunnies.
Unfortunately (again), you can't just remove all obstacles between the bunnies and the escape pods - at most you can remove one wall per escape pod path,
both to maintain structural integrity of the station and to avoid arousing Commander Lambda's suspicions.

You have maps of parts of the space station, each starting at a work area exit and ending at the door to an escape pod.
The map is represented as a matrix of 0s and 1s, where 0s are passable space and 1s are impassable walls.
The door out of the station is at the top left (0,0) and the door into an escape pod is at the bottom right (w-1,h-1).

Write a function solution(map) that generates the length of the shortest path from the station door to the escape pod,
where you are allowed to remove one wall as part of your remodeling plans. The path length is the total number of nodes you pass through,
counting both the entrance and exit nodes. The starting and ending positions are always passable (0). The map will always be solvable,
though you may or may not need to remove a wall. The height and width of the map can be from 2 to 20.
Moves can only be made in cardinal directions; no diagonal moves are allowed.

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
Solution.solution({{0, 1, 1, 0}, {0, 0, 0, 1}, {1, 1, 0, 0}, {1, 1, 1, 0}})
Output:
    7

Input:
Solution.solution({{0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0}})
Output:
    11
*/

import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution3B {

    public static int solution(int[][] map) {
        int[][][] move = new int[2][40][40];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 40; ++j) {
                for (int k = 0; k < 40; ++k) {
                    move[i][j][k] = 9999999;
                }
            }
        }
        PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return Integer.compare(o1.total, o2.total);
            }
        });

        int h = map.length;
        int w = map[0].length;
        move[0][0][0] = 1;
        move[1][0][0] = 1;
        pq.add(new Node(map[0][0], 0, 0, 1));
        Node node;
        while (!pq.isEmpty()) {
            node = pq.poll();
//            if (node.x == h - 1 && node.y == w - 1) return node.total;
            if (node.x + 1 < h && map[node.x + 1][node.y] == 1 && node.take == 0 && move[1][node.x + 1][node.y] > node.total + 1) {
                move[1][node.x + 1][node.y] = node.total + 1;
                pq.add(new Node(1, node.x + 1, node.y, node.total + 1));
            } else if (node.x + 1 < h && map[node.x + 1][node.y] == 0 && node.take <= 1 && move[node.take][node.x + 1][node.y] > node.total + 1) {
                move[node.take][node.x + 1][node.y] = node.total + 1;
                pq.add(new Node(node.take, node.x + 1, node.y, node.total + 1));
            }

            if (node.x - 1 >= 0 && map[node.x - 1][node.y] == 1 && node.take == 0 && move[1][node.x - 1][node.y] > node.total + 1) {
                move[1][node.x - 1][node.y] = node.total + 1;
                pq.add(new Node(1, node.x - 1, node.y, node.total + 1));
            } else if (node.x - 1 >= 0 && map[node.x - 1][node.y] == 0 && node.take <= 1 && move[node.take][node.x - 1][node.y] > node.total + 1) {
                move[node.take][node.x - 1][node.y] = node.total + 1;
                pq.add(new Node(node.take, node.x - 1, node.y, node.total + 1));
            }

            if (node.y + 1 < w && map[node.x][node.y + 1] == 1 && node.take == 0 && move[1][node.x][node.y + 1] > node.total + 1) {
                move[1][node.x][node.y + 1] = node.total + 1;
                pq.add(new Node(1, node.x, node.y + 1, node.total + 1));
            } else if (node.y + 1 < w && map[node.x][node.y + 1] == 0 && node.take <= 1 && move[node.take][node.x][node.y + 1] > node.total + 1) {
                move[node.take][node.x][node.y + 1] = node.total + 1;
                pq.add(new Node(node.take, node.x, node.y + 1, node.total + 1));
            }

            if (node.y - 1 >= 0 && map[node.x][node.y - 1] == 1 && node.take == 0 && move[1][node.x][node.y - 1] > node.total + 1) {
                move[1][node.x][node.y - 1] = node.total + 1;
                pq.add(new Node(1, node.x, node.y - 1, node.total + 1));
            } else if (node.y - 1 >= 0 && map[node.x][node.y - 1] == 0 && node.take <= 1 && move[node.take][node.x][node.y - 1] > node.total + 1) {
                move[node.take][node.x][node.y - 1] = node.total + 1;
                pq.add(new Node(node.take, node.x, node.y - 1, node.total + 1));
            }
        }
        return Math.min(move[1][h - 1][w - 1], move[0][h - 1][w - 1]);
    }

    private static class Node {
        public int total = 0, x, y, take;

        Node(int take, int x, int y, int total) {
            this.take = take;
            this.total = total;
            this.x = x;
            this.y = y;
        }
    }
}