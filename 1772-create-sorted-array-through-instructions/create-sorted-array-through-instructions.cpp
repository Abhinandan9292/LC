class Solution {
public:
    int n=100001;
    int MOD=1e9 + 7;
    vector<int> bits;
    void update(int indx){
        while(indx<n){ 
           bits[indx]++;
            indx+=indx&(-indx);
             
        }
        
    }
    int query(int indx){
        int sum=0;
       
        while(indx>0){
            sum+=bits[indx];
            indx-=indx&(-indx);
        }
        return sum;
    }

    int createSortedArray(vector<int>& instructions) {
        int ans=0;
         bits.assign(n + 1, 0);
        for(int i=0;i<instructions.size();i++){
            int small=query(instructions[i]-1);
            int large=query(instructions[i]);
            int justlarge=i-large;
            ans=(ans+min(small,justlarge))%MOD;
            update(instructions[i]);
        }
        return ans%MOD;
        
    }
};