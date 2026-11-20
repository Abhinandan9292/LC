class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(1000002,0);
        int maxi=0;
        for(auto x:nums){
            dp[x+1]=dp[x]+1;
            dp[x]=dp[x-1]+1;
            maxi=max({dp[x],dp[x+1],maxi});
        }
        return maxi;

        
    }
};