class Solution {
public:
    bool isPalindrome(int n) {
        long long reverse = 0;
        if (n < 0)
            return 0;

        int temp = abs(n);
        while (temp != 0) {
            reverse = (reverse * 10) + (temp % 10);
            temp = temp / 10;
        }

        return (reverse == abs(n));
    }
};