// https://leetcode.com/problems/robot-bounded-in-circle/
// 1041. Robot Bounded In Circle

class Solution {
    public:

    bool isRobotBounded(string instructions) {

        int val = 0;
        char dir = 'N';
        int n = instructions.length();

        int x = 0;
        int y = 0;

        for (int i = 0; i < n; i++) {
            if (instructions[i] == 'L') {
                if (dir == 'N')
                    dir = 'W';

                else if (dir == 'W')
                    dir = 'S';

                else if (dir == 'S')
                    dir = 'E';

                else if (dir == 'E')
                    dir = 'N';
            } else if (instructions[i] == 'R') {
                if (dir == 'N')
                    dir = 'E';

                else if (dir == 'E')
                    dir = 'S';

                else if (dir == 'S')
                    dir = 'W';

                else if (dir == 'W')
                    dir = 'N';
            } else {
                if (dir == 'N')
                    y += 1;

                else if (dir == 'E')
                    x += 1;

                else if (dir == 'S')
                    y -= 1;

                else if (dir == 'W')
                    x -= 1;
            }
        }

        if (x == 0 && y == 0)
            return true;

        if (dir == 'N')
            return false;
        else
            return true;
    }
};
