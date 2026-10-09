class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<char> st;
        int count = 0;

        for(int i = 0; i < n; i++) {

            if(s[i] == '(') {
                st.push(s[i]);
            }
            else {
                // Need a pair of closing brackets ))
                if(i + 1 < n && s[i + 1] == ')') {
                    if(!st.empty()) {
                        st.pop();
                    }
                    else {
                        count++;
                    }
                    i++;
                }
                else {
                    // Only one ')' is available
                    if(!st.empty()) {
                        st.pop();
                        count++;
                    }
                    else {
                        count += 2;
                    }
                }
            }
        }
        return count + 2 * st.size();
    }
};