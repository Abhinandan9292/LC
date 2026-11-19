class Solution {
public:
    int minimizeSum(vector<int>& nums) {
      int ans=0;
      int n=nums.size()-1;
      vector<int> temp;
      temp=nums;
      sort(temp.rbegin(),temp.rend());
      sort(nums.begin(),nums.end());
      ans=nums[n]-nums[2];
      int ans2=0;
      ans2=abs(temp[n]-temp[2]);
      int ans3=0;
      ans3=nums[n-1]-nums[1];
      return min({ans,ans2,ans3});


        
    }
};