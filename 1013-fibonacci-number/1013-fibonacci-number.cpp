class Solution {
private:
    int c(int n, vector<int>& memo) {
        if (n == 0 || n == 1) {
            return n;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        memo[n] = c(n - 1, memo) + c(n - 2, memo);
        return memo[n];
    }

public:
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return c(n, memo);
    }
};