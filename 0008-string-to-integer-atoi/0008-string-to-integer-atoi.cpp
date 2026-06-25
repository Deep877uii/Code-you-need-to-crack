class Solution {
public:

int convert(const string &s, int i, long long num, int sign){
    // If we are out of bounds or at a non-digit, return
    if (i >= s.size() || !isdigit(s[i]))
        return (int)(sign * num);

    // Update num with current digit
    num = num * 10 + (s[i] - '0');

    // Clamp if overflow
    if (sign * num <= INT_MIN) return INT_MIN;
    if (sign * num >= INT_MAX) return INT_MAX;

    // Recurse for next character
    return convert(s, i + 1, num, sign);
}
    int myAtoi(string s) {
        int n = s.size() ;
        int i = 0 ;
        while (i < s.size() && s[i] == ' ') i++;
        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if(s[i]=='-'){
                sign = -1;
            }
            else{
                sign = 1 ;
            }
            i++;
        }
        return convert(s, i, 0, sign);
    }
};