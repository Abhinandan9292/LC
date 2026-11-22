class Solution {
public:
    bool checkString(string s) {
        bool flag=true;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                flag=false;
            }
            if(s[i]=='a' && !flag){
                return false;
            }
        }
        return true;
    }
};