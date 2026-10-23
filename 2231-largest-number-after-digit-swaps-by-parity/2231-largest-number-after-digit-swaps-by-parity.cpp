
class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((s[i] - '0') % 2 == (s[j] - '0') % 2 &&
                    s[i] < s[j]) {
                    swap(s[i], s[j]);
                }
            }
        }

        return stoi(s);
    }
};
