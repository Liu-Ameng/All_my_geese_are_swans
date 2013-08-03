class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool hasStock=false;
        int tot=0;
        for(int i=0;i<prices.size();++i){
            if(hasStock){
                if(prices[i]>=prices[i-1]){
                    tot += prices[i]-prices[i-1];
                    hasStock=false;
                }
            }
            if(!hasStock){
                if(i<prices.size()-1 &&  prices[i]<=prices[i+1]){
                    hasStock = true;
                }
            }
        }
        return tot;
        
    }
};