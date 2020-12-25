#include <iostream>
using namespace std;
typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;
  
  TreeNode(valueType val, TreeNode* right=0, TreeNode* left=0)
    : val(val), right(right),left(left)  {}
};

void insert(TreeNode*& tn, valueType x)
{
    if(!tn) {
        tn = new TreeNode(x);
    } 
	else if(x > tn->val) {
        insert(tn->right, x);
    } 
	else if(x < tn->val) {  
    	insert(tn->left, x);
    }
}

void print(TreeNode* tn, string strings) 
{
    if (!tn) {
    	return;
	}
    print(tn->right, "..." + strings);
    cout << strings << tn->val << endl;
    print(tn->left, "..." + strings);
}

int N, a;

int main() 
{
    TreeNode* head = 0;
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> a;
        insert(head, a);
    }
    print(head, "* ");
}
