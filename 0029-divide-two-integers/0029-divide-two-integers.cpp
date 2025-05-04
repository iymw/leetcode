class Solution {
public:
    int divide(int dividend, int divisor) {
        return (long long)dividend / (long long)divisor > pow(2, 31) - 1
                   ? pow(2, 31) - 1
               : (long long)dividend / (long long)divisor < pow(-2, 31)
                   ? pow(-2, 31)
                   : dividend / divisor;
    }
};