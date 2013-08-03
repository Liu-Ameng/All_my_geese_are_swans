class Solution {
public:
    int start[10000];
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0) return 0;
        int arr[80];
        memset(arr,0,sizeof(arr));
        memset(start,0,sizeof(start));
        start[0]=1;
        arr[s[0]-'a']=1;
        int maxv=1;
        for(int i=1;i<s.size();++i){
            
            if(arr[s[i]-'a']==0){
                arr[s[i]-'a']=1;
                start[i]=start[i-1]+1;
                maxv = max(maxv,start[i]);
            }else{
                for(int j=i-start[i-1];j<i;++j){
                    arr[s[j]-'a']--;
                    
                    if(arr[s[i]-'a']==0){
                        arr[s[i]-'a']=1;
                        start[i] = i-j;
                        maxv = max(maxv,start[i]);
                        break;
                    }
                }
            }
        }
        return maxv;
    }
};

