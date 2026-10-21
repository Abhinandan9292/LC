class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mp;
        int n=strs.size();
        for(int i =0;i<n;i++){
            string temp;
            temp=strs[i];
            sort(temp.begin(),temp.end());
          
            mp[temp].push_back(i);
        }
     
        int count=0;
        for(auto x:mp){
            count++;
        }
           vector<vector<string>> ans(count);
           int indx=0;
        for(auto x:mp){
            for(auto xx:x.second){
            ans[indx].push_back(strs[xx]);
            }
            indx++;

        }
        return ans;

    }
};