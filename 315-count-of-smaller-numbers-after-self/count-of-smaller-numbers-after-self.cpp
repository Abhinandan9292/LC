class Solution {
public: 
 int N = 20001;
        vector<int> bit;
        
void update(int indx,int val){
            while(indx<=N){
                bit[indx]+=val;
                indx+=indx&(-indx);
            }
        }
        int query(int indx){
            int sum=0;
            while(indx>0){
                sum+=bit[indx];
                indx-=indx&(-indx);
            }
            return sum;
        }
    vector<int> countSmaller(vector<int>& nums) {
       
         int n = nums.size();

        bit.assign(N + 1, 0);
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int idx = nums[i] + 10001;

            ans[i] = query(idx - 1);

            update(idx, 1);
        }

        return ans;
    }
};