class Solution {
public:
    int myAtoi(string s) {
       bool w=false;
       int i=0;
       int n=s.length();
       bool neg=false;
       bool f=false;
       while(i<n && s[i]==' '){
        i++;
       }
       if(s[i]=='-'){
        neg=true;
        i++;
       }
        else if(s[i]=='+'){
       i++;
       }
       while(s[i]=='0'){
        i++;
       }
       long long ans=0;
     int start = i;
       int nn=n;
         n=n-i;
       
       while(i<nn){
        if(s[i]>'9' || s[i]<'0'){
            f=true;
           break;
        }
     
        
        ans = ans*10 + (s[i]-'0'); 
          if(ans>INT_MAX){
        if(neg){
              ans=INT_MIN;
              return INT_MIN;
        }
         return INT_MAX;
       }
        i++;
       
     if(f){
    ans /= (long long)pow(10, n-(i-start));
}
       }


       if(ans>INT_MAX){
        if(neg){
              ans=INT_MIN;
              return INT_MIN;
        }
        ans=INT_MAX;
       }
      
       if(neg){
        return -ans;
       }
       return ans;


    }
};