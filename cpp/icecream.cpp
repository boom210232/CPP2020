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
int m,a,x=1,valu,n,y=1;
main()
{
  
  cin >>  m;
  TreeNode* (0) = new TreeNode(0);
  for(int i=0 ; i<m ; i++){
    cin >> n;
    if(n == 1){
    	cin >> a;
    	for(int i=0 ; i<m ; i++){
    		cin >> valu;
    		TreeNode* (x) = new TreeNode(valu);
    		x-1 -> right = x;
		}
		x+=a;
	}
	if(n==2){
		cout << y.data;
		y++;
		
	}
  }
  //TreeNode* root = new TreeNode(20);
  //TreeNode* n1 = new TreeNode(5);
  //TreeNode* n2 = new TreeNode(40);
  //TreeNode* n3 = new TreeNode(35);
  //TreeNode* n4 = new TreeNode(7);
  //n1->right = n4;
  //root->left = n1;
  //root->right = n2;
  //n2->left = n3;
  }
