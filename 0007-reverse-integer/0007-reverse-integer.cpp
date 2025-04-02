class Solution {
public:
    long calculation(int x) {
        int num = x;
        long reversed = 0;
        while (num != 0) {
            int digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }
        if (reversed > 2147483647 || reversed < -2147483648) {
            return 0;
        }
        return reversed;
    }
    int reverse(int x) {
        int num = x;
        if (num > 2147483647 || num < -2147483648) {
            return 0;
        }
        long reversed = calculation(num);
        return reversed;
    }
};