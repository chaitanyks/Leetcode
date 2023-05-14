class CombinationIterator {
public:
    int start;
    int end;
    int len;
    int index;
    vector<string> ans;

    CombinationIterator(string characters, int combinationLength) {
        start = 0;
        end = combinationLength;
        int i = 0;
        int n = pow(2, characters.length());
        for (int i = 0; i < n; i++) {
            int temp = i;
            long long pos = 0;
            string sub = "";
            while (temp != 0) {
                if (temp & 1 == 1) {
                    sub += characters[pos];
                }
                temp = temp >> 1;
                pos++;
            }
            if (sub.length() == combinationLength)
                ans.push_back(sub);
        }
        sort(ans.begin(), ans.end());
        index = 0;
    }

    string next() {
        string val = ans[index];
        index++;
        return val;
    }

    bool hasNext() {
        if (index == ans.size())
            return false;
        else
            return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
