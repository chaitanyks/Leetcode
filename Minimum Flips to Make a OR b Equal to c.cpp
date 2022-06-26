vclass Solution {
public:
    int minFlips(int a, int b, int c) {
        int len = 32;
        bitset<32> ta(a);
        bitset<32> tb(b);
        bitset<32> tc(c);
      
        int ans = 0;
        while (len--) {
            int b1 = ta[0] & 1;
            int b2 = tb[0] & 1;
            int b3 = tc[0] & 1;
            
            if ((b1 | b2) != b3) {
                if (b3 == 0) {
                    if (b1 != 0) ans++;
                    if (b2 != 0) ans++;
                }

                if (b3 == 1) {
                    ans++;
                }
            }
            ta = ta >> 1;
            tb = tb >> 1;
            tc = tc >> 1;
        }
        return ans;
    }
};
