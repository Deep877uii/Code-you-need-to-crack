class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> result(n, 0);
        int prevTime = 0;

        for (string &log : logs) {
            stringstream ss(log);
            string idStr, type, timeStr;

            getline(ss, idStr, ':');
            getline(ss, type, ':');
            getline(ss, timeStr, ':');

            int id = stoi(idStr);
            int timestamp = stoi(timeStr);

            if (type == "start") {
                if (!st.empty()) {
                    result[st.top()] += timestamp - prevTime;
                }

                st.push(id);
                prevTime = timestamp;
            }
            else {
                result[st.top()] += timestamp - prevTime + 1;
                st.pop();
                prevTime = timestamp + 1;
            }
        }

        return result;
    }
};
