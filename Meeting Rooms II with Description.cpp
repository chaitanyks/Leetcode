
// Description:
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
// find the minimum number of conference rooms required.

// Example:
// Input: intervals = [(0,30),(5,10),(15,20)]
// Output: 2
// Explanation:
// We need two meeting rooms
// room1: (0,30)
// room2: (5,10),(15,20)


/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution{
        public:
        /**
         * @param intervals: an array of meeting time intervals
         * @return: the minimum number of conference rooms required
         */

        static bool custom(int &a, int &b)
        {
            return abs(a) < abs(b);
        }

        int minMeetingRooms(vector<Interval> &intervals) {
            // Write your code here
            vector<int> times;
            for (auto &itr:intervals) {
                times.push_back(itr.start);
                times.push_back(-itr.end);
            }

            sort(times.begin(), times.end(), custom);

            int res = 0;
            int ans = 0;
            for (int i = 0; i < times.size(); i++) {
                if (times[i] >= 0) {
                    ans++;
                } else {
                    ans--;
                }
                res = max(res, ans);
            }
            return res;

        }
};
