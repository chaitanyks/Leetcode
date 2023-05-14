#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> &R) {
    map<pair<int, int>, int> mp;
    int n = R.size();
    int m = R[0].size();

    int pi = 0;
    int pj = 0;
    bool check = true;

    //include 0 0
    int ans = 1;

    // 0 1 2 3
    int dir = 0;

    int cycle = 0;
    while (check) {

        check = false;
        //R
        if (dir == 0) {
            int ti = pi;
            int tj = pj + 1;
            while (tj < m && R[ti][tj] == '.') {
                pj = tj;
                if (mp[{ti, tj}] == 0) {
                    // cout<<"R"<<ti<<" "<<tj<<endl;
                    check = true;
                    ans++;
                    mp[{ti, tj}] = 1;
                }
                tj++;
            }
            dir = 1;
        }

        // down
        if (dir == 1) {
            int ti = pi + 1;
            int tj = pj;
            while (ti < n && R[ti][tj] == '.') {
                pi = ti;
                if (mp[{ti, tj}] == 0) {
                    check = true;
                    ans++;
                    mp[{ti, tj}] = 1;
                }
                ti++;
            }
            dir = 2;
        }

        // left
        if (dir == 2) {
            int ti = pi;
            int tj = pj - 1;
            while (tj >= 0 && R[ti][tj] == '.') {
                pj = tj;
                if (mp[{ti, tj}] == 0) {
                    check = true;
                    ans++;
                    mp[{ti, tj}] = 1;
                }
                tj--;
            }
            dir = 3;
        }

        //up
        if (dir == 3) {
            int ti = pi - 1;
            int tj = pj;
            while (ti >= 0 && R[ti][tj] == '.') {
                pi = ti;
                if (mp[{ti, tj}] == 0) {
                    check = true;
                    ans++;
                    mp[{ti, tj}] = 1;
                }
                ti--;
            }
            dir = 0;
        }

        // check cycle
        if (!check) {
            if (cycle != 4) {
                cycle++;
                check = true;
            }
        } else {
            cycle = 1;
        }
    }

    return ans;
}


int main() {
    // your code goes here
    vector<string> R;
// 	R={"....X..","X......",".....X.","......."};
    R = {"...x.", ".x..x", "x...x", "..x.."};
    cout << solution(R) << endl;
    return 0;
}
