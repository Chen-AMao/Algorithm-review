include<iostream>
include<cstdio>
include<string>
include<stack>
include<vector>
include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Command {
	string s;
	TreeNode* node;
	Command(string s, TreeNode* node): s(s), node(node) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
		if (root == NULL) return res;
		
		stack<Command> c;
		c.push(Command("go",root));
		while(!c.empty()) {
			Command tmpC = c.top();
			c.pop();
			if (tmpC.s == "print") {
				res.push_back(tmpC.node->val);
			} else {
				assert(tmpC.s == "go");
                if (tmpC.node->right) c.push(Command("go", tmpC.node->right));
				if (tmpC.node->left) c.push(Command("go", tmpC.node->left));
				c.push(Command("print", tmpC.node));
			}
		}
		return res;
    }
};


int main() {
	
}
