class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minn=nums[0];
        
        long long ans=0;
        for(int i=0;i<nums.size();i++){
          minn=min(minn,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            ans+=nums[i]-minn;
        }
        return ans;
        
    }
};