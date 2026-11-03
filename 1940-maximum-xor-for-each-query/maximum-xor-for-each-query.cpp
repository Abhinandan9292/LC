class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> pre;
        int p=pow(2,maximumBit)-1;
        int val=0;
        for(int i=0;i<nums.size();i++){
            val^=nums[i];
            pre.push_back(val);
        }
        reverse(pre.begin(),pre.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(pre[i]^p);
        }
        return ans;

    }
};