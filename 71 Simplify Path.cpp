#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string tmp;
        for (int i=0; i<path.length(); i++) {
        	if (path[i] == '/') {
        		if (tmp == "") continue;
        		else {
        			s.push(tmp);
        			tmp = "";
				}
			}
			else if (i == path.length()-1) {
				tmp += path[i];
				if (tmp != "") {
        			s.push(tmp);
        			tmp = "";
				}
			}
        	else {
        		tmp += path[i];
			}
		}
		
		stack<string> ss;
		while(!s.empty()) {
			ss.push(s.top());
			s.pop();
		}
			
		while(!ss.empty()) {
			string t = ss.top();
			ss.pop();
			if (t == "..") {
				if (!s.empty()) s.pop();
			}
			else if (t == ".") {
			}
			else {
				s.push(t);
//				cout<<t<<endl;
			}
		}
			
		if (s.empty()) return "/";
		else {
			while (!s.empty()) {
				ss.push(s.top());
				s.pop();
			}
			string ans = "";
			while(!ss.empty()) {
				ans += '/' + ss.top();
				ss.pop();
			}
			return ans;
		}	
    }
};

int main() {
	string s;
	while(cin>>s) {
		Solution solution;
		string ans = solution.simplifyPath(s);
		cout<<ans<<endl;
	}
	return 0;
}
 
