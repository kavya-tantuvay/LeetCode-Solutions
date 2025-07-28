class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
    int maxOr = 0;  // To store the maximum OR
    int count = 0;  // To count subsets with maximum OR

    // Calculate the maximum OR by iterating over all subsets
    for (int mask = 0; mask < (1 << n); mask++) {
        int orValue = 0;

        // Compute OR for the current subset
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {  // If the i-th bit is set, include nums[i] in the subset
                orValue |= nums[i];
            }
        }

        // Update the maximum OR and count the subsets
        if (orValue > maxOr) {
            maxOr = orValue;
            count = 1;  // Reset the count for new maximum
        } else if (orValue == maxOr) {
            count++;  // Increment the count for the current maximum OR
        }
    }

    return count;

        
    }
};