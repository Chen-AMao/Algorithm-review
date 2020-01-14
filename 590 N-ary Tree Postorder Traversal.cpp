/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
struct Command {
    string s;
    Node* node;
    Command(string _s, Node* _node): s(_s), node(_node) {};
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        
        stack<Command> st;
        st.push(Command("go", root));
        while(!st.empty()) {
            Command tmp = st.top();
            st.pop();
            if (tmp.s == "print") {
                res.push_back(tmp.node->val);
            } else {
                assert(tmp.s == "go");
                st.push(Command("print", tmp.node));
                if (tmp.node->children.size()>0) {
                    for(int i=tmp.node->children.size()-1; i>=0; i--) {
                        // if (tmp.node->children[i])
                            st.push(Command("go", tmp.node->children[i]));
                    }
                }
                
            }
        }
        return res;
    }
};
