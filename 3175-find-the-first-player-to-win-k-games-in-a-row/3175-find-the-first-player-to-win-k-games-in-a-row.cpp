class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int max_el = INT_MIN;
        int id = -1;

        if(n - 1 <= k) {
            for(int i = 0; i < n; i++) {
                if(skills[i] > max_el) {
                    max_el = skills[i];
                    id = i;
                }
            }
            return id;
        }
        else {
            unordered_map<int, int> mpp;
            deque<int> q;

            for(int i = 0; i < n; i++) {
                q.push_back(i);
            }

            while(true) {
                int id1 = q.front();
                q.pop_front();

                int id2 = q.front();
                q.pop_front();

                if(skills[id1] > skills[id2]) {
                    q.push_front(id1);
                    mpp[id1]++;
                    q.push_back(id2);

                    if(mpp[id1] == k) {
                        id = id1;
                        break;
                    }
                }
                else {
                    q.push_front(id2);
                    mpp[id2]++;
                    q.push_back(id1);

                    if(mpp[id2] == k) {
                        id = id2;
                        break;
                    }
                }
            }
        }

        return id;
    }
};