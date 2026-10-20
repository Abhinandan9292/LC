class Solution {
public:
    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = INT_MIN;

        for (int i = 0; i < n; i += k) {
            int cnt = 0, pos = -1;

            for (int j = 0; j < k; j++) {
                int curr = nums[i + j];
                int next = nums[i + (j + 1) % k];

                if (curr > next) {
                    cnt++;
                    pos = j;
                }
            }

            if (cnt > 1) return false;

            int first, last;

            if (cnt == 0) {
                first = nums[i];
                last = nums[i + k - 1];
            } else {
                first = nums[i + (pos + 1) % k];
                last = nums[i + pos];
            }

            if (first < prev) return false;

            prev = last;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (check(nums, i)) ans += i;

                if (i != n / i && check(nums, n / i)) {
                    ans += n / i;
                }
            }
        }

        return ans;
    }
};