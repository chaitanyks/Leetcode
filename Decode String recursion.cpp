class Solution {
public:

    string solve(string s, int start, int end) {

        int n = s.length();
        if (start >= n || end >= n)
            return "";

        string ans = "";
        string prefix = "";
        string suffix = "";

        int count = 0;
        int tstart = start;
        // int tend = end;

        while (tstart < n && s[tstart] <= 'z' && s[tstart] >= 'a') {
            prefix += s[tstart];
            tstart++;
        }

        while (tstart < n && s[tstart] <= '9' && s[tstart] >= '0') {
            count = count * 10 + s[tstart] - '0';
            tstart++;
        }

        // cout<<prefix<<" "<<count<<endl;

        int tend = tstart + 1;
        int ob = 1;
        int cb = 0;
        while (tend < n && ob != cb) {
            if (s[tend] == '[')
                ob++;
            if (s[tend] == ']')
                cb++;
            tend++;
        }

        string pattern;

        if (ob == 1 && cb == 1) {
            // cout<<tstart<<" "<<tend<<endl;
            for (int j = tstart + 1; j < tend - 1; j++) {
                pattern += s[j];
            }
        } else if (ob == cb) {
            cout << tstart << " " << tend << endl;
            tstart++;
            while (tstart < n && s[tstart] >= 'a' && s[tstart] <= 'z') {
                pattern += s[tstart];
                tstart++;
            }
            string end;
            tend = tend - 2;
            while (tend >= 0 && s[tend] >= 'a' && s[tend] <= 'z') {
                end += s[tend];
                tend--;
            }
            pattern += solve(s, tstart, tend);
            pattern += end;

        }

        while (count--)
            ans += pattern;

        string extra;

        if (tend <= end) {
            // cout<<tend<<" "<<end<<endl;
            extra = solve(s, tend, end);
        }

        return prefix + ans + extra;
    }

    string decodeString(string s) {
        int n = s.length();
        return solve(s, 0, n - 1);
    }
};
