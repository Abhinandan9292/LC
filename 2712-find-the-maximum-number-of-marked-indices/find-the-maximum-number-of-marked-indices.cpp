class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int i=nums.size()/2;
        int j=0;
        int ans=0;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<int> num(nums.size(),0);
        while(i<nums.size()){
            if(nums[i]*2<=nums[j]){
                ans+=2;
                num[i]=1;
                num[j]=1;
                while(j<nums.size() && num[j]){
                    j++;
                }
                while(i<nums.size() && num[i]){
                    i++;
                }
            }
            else{
                i++;
            }
        }
        return ans;
        
    }
};