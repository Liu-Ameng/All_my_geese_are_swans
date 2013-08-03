class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dp[s.size()+1];
        if(s=="" || s[0]=='0') return 0;
        dp[0]=1;        
        dp[1]=1;
        for(int i=1;i<s.size();++i){
            dp[i+1]=0;
            if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')){
                dp[i+1] += dp[i-1];
            }
            if(s[i]!='0'){
                dp[i+1] += dp[i];
            }                
        }
        return dp[s.size()];
    }
};