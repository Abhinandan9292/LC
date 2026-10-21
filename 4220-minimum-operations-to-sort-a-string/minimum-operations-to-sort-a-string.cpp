class Solution {
public:
    int minOperations(string s) {
          string temp;
        temp=s;
        sort(temp.begin(),temp.end());
        if(temp==s){
            return 0;
        }
       int minn = INT_MAX;
int minIdx = -1;

for (int i = 0; i < s.length(); i++) {
    if (s[i] - 'a' < minn) {
        minn = s[i] - 'a';
        minIdx = i;
        
    }
}

int maxi = -1;
int maxIdx = -1;

for (int i = 0; i < s.length(); i++) {
    if (s[i] - 'a' >=maxi) {
        maxi = s[i] - 'a';
        maxIdx = i;
    }
}
       int n = s.length();

if (n == 2) {
    return -1;
}
if (minIdx == 0 || s[n - 1] - 'a' == maxi) {
    return 1;
}
if (maxIdx == 0 && minIdx == n - 1) {
    return 3;
}
return 2;


        
    }
};