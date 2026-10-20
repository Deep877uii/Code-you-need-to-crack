class Solution {
public:
    vector<int> LPS(vector<int>& pat) {
        int n = pat.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool KMPsearch(vector<int>& pat, vector<int>& text) {
        int n = pat.size();
        int m = text.size();

        vector<int> lps = LPS(pat);

        int i = 0, j = 0;

        while (i < m) {
            if (text[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == n) {
                return true;
            }
            else if (i < m && text[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return false;
    }

    bool isValid(vector<int>& vec1, vector<int>& vec2) {
        vector<int> text = vec2;
        text.insert(end(text), begin(vec2), end(vec2));

        return KMPsearch(vec1, text);
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));

        int result = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                vector<int> vec1(
                    begin(nums) + start,
                    begin(nums) + start + k
                );

                vector<int> vec2(
                    begin(sorted) + start,
                    begin(sorted) + start + k
                );

                if (!isValid(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result += k;
            }
        }

        return result;
    }
};