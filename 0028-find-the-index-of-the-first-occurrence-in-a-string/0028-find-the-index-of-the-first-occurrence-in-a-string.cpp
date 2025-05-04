class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.contains(needle) ? haystack.find(needle) : -1;
    }
};