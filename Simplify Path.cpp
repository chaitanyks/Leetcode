// https://leetcode.com/problems/simplify-path/
// 71. Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ans;
        stringstream s(path);
        string temp;

        while (getline(s, temp, '/')) {
            if (temp == "" || temp == ".")
                continue;
            else if (temp == "..") {
                if (!ans.empty())
                    ans.pop();
            } else
                ans.push(temp);
        }

        string finalPath;

        if (ans.size() == 0)
            finalPath = "/";
        else {
            while (!ans.empty()) {
                finalPath = "/" + ans.top() + finalPath;
                ans.pop();
            }
        }

        return finalPath;
    }
};
