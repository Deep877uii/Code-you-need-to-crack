class Solution {
public:
    const long long MOD = 1000000007LL;

    vector<long long> sum, sq, lazy;

    void applyAdd(int node, int len, long long v) {
        sq[node] = (sq[node] + 2 * v % MOD * sum[node] % MOD + v * v % MOD * len % MOD) % MOD;
        sum[node] = (sum[node] + v * len) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }

    void push(int node, int low, int high) {
        if (lazy[node] == 0) return;

        int mid = low + (high - low) / 2;

        applyAdd(node * 2, mid - low + 1, lazy[node]);
        applyAdd(node * 2 + 1, high - mid, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int low, int high, int l, int r) {
        if (l > high || r < low) return;

        if (l <= low && high <= r) {
            applyAdd(node, high - low + 1, 1);
            return;
        }

        push(node, low, high);

        int mid = low + (high - low) / 2;
        update(node * 2, low, mid, l, r);
        update(node * 2 + 1, mid + 1, high, l, r);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;
            if (last.find(nums[i]) != last.end()) {
                prev = last[nums[i]];
            }

            update(1, 0, n - 1, prev + 1, i);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return (int)ans;
    }
};