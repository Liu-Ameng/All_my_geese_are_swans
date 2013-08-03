#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct Node{
	int s,e;
};
vector<vector<Node> >ret2;

bool isPalin(const string& str, int s, int e){
	for(int i=s,j=e;i<j;++i,--j){
		if(str[i]!=str[j])
		return false;	
	}
	return true;
}
	        
bool DFS(vector<Node> &tmp, int end, const string & s){
	if(end==s.size()-1){
		ret2.push_back(tmp);
		return true;
	}
	for(int i=end+1;i<s.size();++i){
		if(isPalin(s,end+1,i)==false)
		continue;
		Node a;
		a.s=end+1; a.e=i;
		tmp.push_back(a);
		DFS(tmp,i,s);
		tmp.pop_back();
	}
}

vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<string> > ret;
		ret.clear();
		ret2.clear();
		vector<Node> tmp;
		Node a,b;
		for(int i=0;i<s.size();++i){
			if(isPalin(s,0,i)==false)
			continue;
			tmp.clear();
			a.s=0;
			a.e=i;
			tmp.push_back(a);
			DFS(tmp,i,s);
			}
		for(int i=0;i<ret2.size();++i){
			vector<string> tmp2;
			tmp.clear();
			for(int j=0;j<ret2[i].size();++j){
				tmp2.push_back(s.substr(ret2[i][j].s,ret2[i][j].e-ret2[i][j].s+1));
			}
			ret.push_back(tmp2);
		}
		return ret;
    }



int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	string s;
	while(cin>>s){
		partition(s);
	}
}