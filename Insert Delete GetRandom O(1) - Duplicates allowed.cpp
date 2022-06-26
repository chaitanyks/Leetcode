class RandomizedCollection {
public:
    multiset<long long> st;
    vector<long long> vct;
    RandomizedCollection() {
        st.clear();
    }
    
    // void vect(multiset<long long> st) {
    //     auto itr = st.begin();
    //     while(itr!=st.end())
    //     {
    //         vct.push_back(*itr);
    //         itr++;
    //     }
    // }
    
    bool insert(int val) {
                
        if(st.find(val) == st.end())
        {
            st.insert(val);
            // auto itr = st.find(val);
            // cout<<*itr<<endl;
        // pos[st.begin()-itr] = itr;\
            // vect(st);
            vct.push_back(val);
            return true;
        }
        else{
            st.insert(val);
            auto itr = st.find(val);
        // pos[st.begin()-itr] = itr;
            // vect(st);
            vct.push_back(val);
            return false;
        }
        
    }
    
    bool remove(int val) {
        sort(vct.begin(),vct.end());
        // for(int i = 0;i<vct.size();i++)
        // {
        //     cout<<vct[i]<<" ";
        // }
        // cout<<endl;
        
        if(st.find(val) != st.end())
        {
            auto itr = st.begin();
            auto itr1 = st.find(val);
            int index = 0;
            while(itr!=itr1)
            {
                itr++;
                index++;
            }
            vct.erase(vct.begin()+index);
            st.erase(st.find(val));
            // vect(st);
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
        // auto itr = st.begin();
        // for(int i =0;i<vct.size();i++)
        // {
        //     cout<<vct[i]<<" ";
        // }
        // cout<<endl;
        long long s= st.size();
        // long long ran = 0;
        long long ran = rand()%s;
        
        // cout<<s<<" "<<ran<<endl;
        
        // cout<<*itr<<endl;
        return vct[ran];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
