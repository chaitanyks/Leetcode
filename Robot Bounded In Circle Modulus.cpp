// https://leetcode.com/problems/robot-bounded-in-circle/
// 1041. Robot Bounded In Circle

class Solution {
public:
    bool isRobotBounded(string instructions) {

        int val = 0;
        int dir = 0;
        int n = instructions.length();

        int x = 0;
        int y = 0;

        for (int i = 0; i < n; i++) {
            if (instructions[i] == 'L') {
                dir = (dir - 1) % 4;
            } 
            else if (instructions[i] == 'R') {
                dir = (dir + 1) % 4;
            } 
            else {
                if (dir == 0)
                    y += 1;

                else if (dir == 1)
                    x += 1;

                else if (dir == 2)
                    y -= 1;

                else if (dir == 3)
                    x -= 1;
            }

            if (dir < 0)
                dir += 4;
        }

        if (x == 0 && y == 0)
            return true;

        if (dir == 0)
            return false;
        else
            return true;
    }
};
