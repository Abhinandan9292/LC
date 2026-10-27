class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string temp;
        temp+='.';
        for(int i=0;i<n-1;i++){
            temp+='#';
        }
        for(int i=0;i<m-1;i++){
            ans.push_back(temp);
        }
        string v;
        for(int i=0;i<n;i++){
            v+='.';
        }
        ans.push_back(v);
        return ans;
        
    }
};