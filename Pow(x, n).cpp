class Solution {
public:

    double fastPow(double x, int n) {
        if (n == 0)
            return 1;
        double prod = fastPow(x, n / 2);

        if (n % 2 == 0)
            return prod * prod;

        return x * prod * prod;
    }

    double myPow(double x, int n) {
        if (n < 0)
            return fastPow(1 / x, n);

        return fastPow(x, n);
    }
};
