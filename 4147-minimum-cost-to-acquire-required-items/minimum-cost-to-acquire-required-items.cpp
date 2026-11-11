class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(costBoth<cost1 && costBoth<cost2){
            return (long long)(1LL*max(need1,need2))*costBoth;
        }
          else if(costBoth>cost1 && costBoth>cost2 && costBoth<cost1+cost2){
           if(need1>need2){
            ans+=1LL*(costBoth)*need2;
            need1-=need2;
            ans+=1LL*need1*cost1;
           }
           else{
            ans+=1LL*(costBoth)*need1;
            need2-=need1;
            ans+=1LL*need2*cost2;
           }
           return ans;
        }
        else if(costBoth>cost1 && costBoth>cost2){
            ans+=1LL*(need1)*cost1;
            ans+=1LL*(need2)*cost2;
            return ans;
        }
        else if(costBoth>=cost1 && costBoth<cost2){
            ans+=(1LL*need2*costBoth);
            need1=need1-need2;
            if(need1>0){
                ans+=1LL*need1*cost1;
            }
             return ans;
        }
        else{
             ans+=1LL*costBoth*need1;
            need2-=need1;
            if(need2>0){
                ans+=1LL*need2*cost2;
            }


        }
        return ans;
    }
};