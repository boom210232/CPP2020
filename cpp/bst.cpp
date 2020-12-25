#include <iostream>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0)
    : val(val), left(left), right(right) {}
};

int main()
{
	int time,choice,a;
    TreeNode* head = new TreeNode(0);
	TreeNode* tail = head;
	TreeNode* point = head;
    cin >> time ;
	for(int i = 0 ; i<time ; i++){
		cin >> choice;
		if(choice == 1){
			cin >> a;
			tail->right = new TreeNode(a);
			tail = tail->right;
		}
		else if(choice == 2){
			cin >> a;
			if(point->right->val == a){
				cout << 1 << endl;
				point = point->right;
			}
			else if (point->right == NULL) cout << 0;
			else if(point->right->val != a){
				cout << 0 <<endl;
			}
		}
	}
	return 0;
}
  



