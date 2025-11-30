class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int n = nums.size();
        long total_sum = 0;

        for (int num : nums) {
            total_sum += num;
        }

        int rem = total_sum % p;
        if (rem == 0) return 0;

        unordered_map<int, int> prefix_mod;
        prefix_mod[0] = -1;
        
        int min_len = n;
        long prefix_sum = 0;

        for (int i = 0; i < n; i++) {
            prefix_sum += nums[i];
            int current_mod = prefix_sum % p;

            int target_mod = (current_mod - rem + p) % p;

            if (prefix_mod.find(target_mod) != prefix_mod.end()) {
                int prev_index = prefix_mod[target_mod];
                min_len = min(min_len, i - prev_index);
            }

            prefix_mod[current_mod] = i;
        }

        return min_len == n ? -1 : min_len;
    }
};





