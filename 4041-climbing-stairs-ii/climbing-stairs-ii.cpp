class Solution {
public:
    int solve(int n,vector<int> &costs,int indx,vector<int> &dp){
        if(indx==n){
            return 0;
        }

        if(dp[indx]!=-1){
            return dp[indx];
        }

        int ans=INT_MAX;

        for(int i=1;i<=3;i++){
            int newval=INT_MAX;

            if(indx+i<=n){
                newval=costs[indx+i-1]+solve(n,costs,indx+i,dp)+i*i;
            }

            ans=min(newval,ans);
        }

        return dp[indx]=ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        int ans=solve(n,costs,0,dp);
        return ans;
    }
};