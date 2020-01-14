#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") { // operators
                int tmp1 = stringToNum(st.top());
                st.pop();
                int tmp2 = stringToNum(st.top());
                st.pop();
                int tmp;
                if (tokens[i] == "+") tmp = tmp2 + tmp1;
                else if (tokens[i] == "-") tmp = tmp2 - tmp1;
                else if (tokens[i] == "*") tmp = tmp2 * tmp1;
                else if (tokens[i] == "/") tmp = tmp2 / tmp1;
                st.push(numToString(tmp));
            } else {
                st.push(tokens[i]);
            }
        }
        return stringToNum(st.top());
    }
    
    int stringToNum (string s) {
    	bool isNeg = false;
    	if (s[0] == '-') isNeg = true;
        int base = 1;
        int ans = 0;
        int range = isNeg ? 1 : 0;
        for (int i=s.length() - 1; i>=range; i--) {
            ans += (s[i]-'0')*base;
            base *= 10;
        }
        return (isNeg ? -ans : ans);
    }
    
    string numToString (int n) {
    	string s = "";
    	bool isNeg = false;
    	if (n<0) {
    		isNeg = true;
    		n = -n;
		}
        while (n) {
            s += n%10 + '0';
            n /= 10;
        }
        int len = s.length();
        for (int i=0; i<len/2; i++) {
            char tmp = s[i];
            s[i] = s[len-i-1];
            s[len-i-1] = tmp;
        }
        return isNeg ? "-"+s : s;
    }
};

vector<string> tokens;
int main() {
	int i,j;
	string s;
	int n;
	cin>>i>>j;
	while(n--) {
		cin>>s;
		tokens.push_back(s);
	}
	Solution solution;
	int ans = solution.evalRPN(tokens);
	cout<<"ans="<<ans<<endl;
	return 0;
}
 
