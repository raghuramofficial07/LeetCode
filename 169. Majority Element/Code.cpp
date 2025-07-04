class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int majority = nums[0];

        for (int i = 0; i < n;) {
            int current = nums[i];
            count2 = 0;
            while (i < n && nums[i] == current) {
                count2++;
                i++;
            }
            if (count2 > count1) {
                count1 = count2;
                majority = current;
            }
        }
        return majority;
    }
};
