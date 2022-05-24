/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node*> qu;
        // root->next=NULL;
        qu.push(root);
        while(!qu.empty()){
            int z=qu.size();
            Node* temp=NULL;
            for(int i=0;i<z;i++){
                auto a1=qu.front();
                if(a1->left)
                    qu.push(a1->left);
                if(a1->right)
                    qu.push(a1->right);
                if(temp){
                    temp->next=a1;
                }
                temp=a1;
                qu.pop();
            }
            temp->next=NULL;
        }
        return root;
    }
};