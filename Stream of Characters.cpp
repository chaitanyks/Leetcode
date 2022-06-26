class Trie {
public:
    Trie *children[26];
    bool isEnd;

    Trie() {
        this->isEnd = false;
        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
    }

    void insert(string word) {
        reverse(word.begin(), word.end());
        Trie *node = this;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (node->children[index] == NULL) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie *node = this;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (node->children[index] == NULL)
                return false;

            node = node->children[index];

            if (node->isEnd == true)
                return true;
        }
        return false;
    }
};


class StreamChecker {
public:
  
    Trie root;
    string stream;
    int maxLen = 0;

    StreamChecker(vector<string> &words) {

        for (int i = 0; i < words.size(); i++) {
            root.insert(words[i]);
            if (words[i].length() > maxLen)
                maxLen = words[i].length();
        }
    }

    bool query(char letter) {
        stream = letter + stream;
        if (stream.length() > maxLen) {
            stream = stream.substr(0, maxLen);
        }
      
        return root.search(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
