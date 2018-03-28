#include <iostream>
#include <cstdlib>
using namespace std;

class TreeNode{
private:
	float value;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(float val){
		value = val;
		left = NULL;
		right = NULL;
	}
	float getValue(){
		return value;
	}
	TreeNode* getLeft(){
		return left;
	}
	TreeNode* getRight(){
		return right;
	}
	void setLeft(TreeNode* node){
		left = node;
	}
	void setRight(TreeNode* node){
		right = node;
	}

};

class BinaryTree{
private:
	TreeNode* root;
public:
	BinaryTree(){
		root = NULL;
	}
	TreeNode* getRoot(){return root;}
	void InsertNode(TreeNode* node){
		if(!root){
			root = node;
			return;
		}
		TreeNode* tmp = root;
		while(tmp){
			if(node->getValue() >= tmp->getValue()){
				if(!tmp->getRight()){
					tmp->setRight(node);
					break;
				} 
				tmp = tmp->getRight();
			}
			else{
				if(!tmp->getLeft()){
					tmp->setLeft(node);
					break;
				} 
				tmp = tmp->getLeft();
			}
		}
		
	}
	void PrintTree(TreeNode* node){
		if(!node) return;
		if(node->getLeft()) PrintTree(node->getLeft());
		cout<<node->getValue()<<" ";
		if(node->getRight()) PrintTree(node->getRight());

	}
};

int main(){
	BinaryTree BT;

	while(1){
		int choice;
		cin>>choice;
		switch(choice){
			case 1:{
				float v;
				cout<<"Insert A Node: ";
				cin>>v;
				TreeNode* node = new TreeNode(v);
				BT.InsertNode(node);
				cout<<endl;
				break;
			}
			case 2:{
				cout<<"Print Tree."<<endl;
				BT.PrintTree(BT.getRoot());
				cout<<endl; 
				break;
			}
			case 3:{
				return 0;
				break;
			}
		}
	}
	return 0;
}



