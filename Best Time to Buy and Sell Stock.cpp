class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size()==0) return 0;
        int maxv=0,tmp=0,dp=prices[0];
        for(int i=1;i<prices.size();++i){
            tmp = max(0,prices[i]-dp);
            if(tmp==0) dp = prices[i];
            maxv = max(tmp,maxv);
        }
        return maxv;
    }
};