#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
struct TreeNode
{
    int data;
    TreeNode * left;
    TreeNode * right;
};

class BinarySearchTree
{
private:
    TreeNode * root;
public:
    BinarySearchTree(){
        root = new TreeNode();
    }

    ~BinarySearchTree(){};

	void swap(int &a, int &b){
		int temp = a;
		a = b;
		b = temp;
	}

    int countNodes(TreeNode * head){
        if(!head){
            return 0;
        }
        return countNodes(head->left) + countNodes(head->right) + 1;
    }

    TreeNode* treeSearch(TreeNode * head, int key){
        if(!head || key == head->data){
            return head;
        }
        if(key < head->data){
            return treeSearch(head->left, key);
        }
        return treeSearch(head->right, key);
    }

    TreeNode * minimum(TreeNode * head){
        while(head->left){
            head = head->left;
        }
        return head;
    }
    TreeNode * maximum(TreeNode * head){
        while(head->right){
            head = head->right;
        }
        return head;
    }

    TreeNode * buildTreeNode(int n){
        TreeNode * node = new TreeNode();
        node->data = n;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }

    void insert(TreeNode * head, int num){
        if(!head){
            head = buildTreeNode(num);
        } else if(num < head->data){
            insert(head->left, num);
        } else {
            insert(head->right, num);
        }
    }
};

#endif