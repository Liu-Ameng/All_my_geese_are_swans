class Solution {
public:
    
    bool isIp(string s){
        if(s.size()==0) return false;
        if(s.size()==1) return true;
        if(s.size()==2 && s[0]!='0') return true;
        if(s.size()==2 && s[0]=='0') return false;
        if(s.size()>3) return false;
        if(s[0]=='0') return false;
        if(s[0]>'2') return false;
        if(s[0]<'2') return true;
        if(s[1]>'5') return false;
        if(s[1]<'5') return true;
        if(s[2]>'5') return false;
        return true;
    }
    vector<string> res;
    
    void DFS(string s,int p,int c){
        if(c==3){
            if(isIp(s.substr(p))){
                res.push_back(s);
                return;
            }
        }
        string tmp=s;
        for(int i=p;i<=p+2 && i<s.size();++i){
            if(isIp(s.substr(p,i-p+1))){
                tmp.insert(i+1,".");
                DFS(tmp,i+2,c+1);
                tmp = s;
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        if(s.size()>13) return res;
        DFS(s,0,0);
        return res;
    }
};

