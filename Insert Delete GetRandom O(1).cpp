
class RandomizedSet {
public:
    unordered_set<int> st;

    RandomizedSet() {
        st.clear();
    }

    bool insert(int val) {
        if (st.find(val) == st.end()) {
            st.insert(val);
            return true;
        } else
            return false;
    }

    bool remove(int val) {

        if (st.find(val) != st.end()) {
            st.erase(st.find(val));
            return true;
        } else
            return false;
    }

    int getRandom() {
        // auto itr = st.begin();

        int s = st.size();
        int ran = rand() % s;
        // cout<<s<<" "<<ran<<endl;
        auto itr = st.begin();
        advance(itr, ran);
        // cout<<*itr<<endl;
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
