class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p=0;
        int q=nums.size()-1;
        int ans=nums.size();
        while(p<=q) {
            if (nums[p] == val) {
                swap(nums[p],nums[q--]);
                ans--;
            } else p++;
        }
        return ans;
    }
};
