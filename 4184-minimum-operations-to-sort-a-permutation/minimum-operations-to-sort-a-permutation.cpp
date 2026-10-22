class Solution {
public:
 int indx=0;
 int indx1=0;
 bool check(vector<int>& nums) {
     int count=0;
     int n=nums.size() ;
     for(int i=1;i<n;i++){
        if(nums[i-1]>nums[i]){
            count++;
            indx=i;
        }


     }
     if(nums[n-1]>nums[0]){
        count++;
     }
     return count<=1;
     
        
    }
    bool check1(vector<int>& nums) {
     int count=0;
     int n=nums.size() ;
     for(int i=1;i<n;i++){
        if(nums[i-1]<nums[i]){
            count++;
            indx1=i;
        }


     }
     if(nums[n-1]<nums[0]){
        count++;
     }
     return count<=1;
     
        
    }
    int minOperations(vector<int>& nums) {
        bool in=true;
        int n=nums.size();
        bool fl=check1(nums);
        vector<int> temp,temp1;
        temp=nums;
        temp1=nums;
        sort(temp.begin(),temp.end());
        reverse(temp1.begin(),temp1.end());
        if(n>1&&temp1==temp){
            return 1;
        }

        if(!check(nums) && !fl){
            return -1;
        }
       if (check(nums)) {
    return min(indx, n - indx + 2);
}

   return 1 + min(indx1, n - indx1);
        
    }
};