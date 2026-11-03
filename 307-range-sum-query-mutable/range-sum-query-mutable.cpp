class NumArray {
public:
    int n;
    vector<int> bit;
    vector<int> nums;
    
    int query(int indx){
        int sum=0;
        while(indx>0){
            sum+=bit[indx];
            indx -= indx & (-indx);
        }
        return sum;
    }
    NumArray(vector<int>& nums) {
        this->nums=nums;
        n=nums.size();
        bit.assign(n+1,0);
        for(int i=0;i<n;i++){
            int indx=i+1;
            while(indx<=n){
                bit[indx]+=nums[i];
                indx+=indx&(-indx);
            }
        }
        
    }
    
    void update(int index, int val) {
        int delta=val-nums[index];
        nums[index]=val;
        index++;
          while(index<=n){
            bit[index]+=delta;
            index+=index&(-index);
        }

    }
    
    int sumRange(int left, int right) {
       int val=-query(left)+query(right+1);
        return val;
       
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */