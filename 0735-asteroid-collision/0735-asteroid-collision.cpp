class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++) {

            int curr = asteroids[i];
            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && curr < 0) {

                if(st.top() < abs(curr)) {
                    st.pop();               // stack asteroid destroyed
                }
                else if(st.top() == abs(curr)) {
                    st.pop();               // both destroyed
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;       // current asteroid destroyed
                    break;
                }
            }

            if(!destroyed)
                st.push(curr);
        }

        vector<int> ans(st.size());

        for(int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};