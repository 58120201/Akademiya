#pragma once
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

template<class T>
class BinaryTree;
template<class T>
class TreeNode
{
	friend class BinaryTree<T>;
private:
	T data;
	TreeNode<T>* leftchild;
	TreeNode<T>* rightchild;
public:
	TreeNode<T>(T x = 0, TreeNode<T>* bt1 = NULL, TreeNode<T>* bt2 = NULL);
};
template<class T>
TreeNode<T>::TreeNode(T x, TreeNode<T>* bt1, TreeNode<T>* bt2)
{
	data = x;
	leftchild = bt1;
	rightchild = bt2;
}

template<class T>
class BinaryTree
{
public:
	TreeNode<T>* root;
public:
	BinaryTree();
	BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);
	BinaryTree(const BinaryTree<T>& t);
	TreeNode<T>* copy(TreeNode<T>* origNode);
	void clear();

	bool isempty();
	BinaryTree<T> Leftsubtree();
	BinaryTree<T> Rightsubtree();
	T rootdata();
	void display();

	void preorder();                                   //先序递归
	void preorder(TreeNode<T>* currentNode);
	void preiterator();                                //先序迭代    

	void inorder();                                    //中序递归
	void inorder(TreeNode<T>* currentNode);
	void initerator();                                 //中序迭代

	void postorder();                                  //后序递归
	void postorder(TreeNode<T>* currentNode);
	void postiterator();                               //后序迭代

	void leveliterator();                              //层序迭代
};
template<class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}
template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2)
{
	root = new TreeNode<T>;
	root->data = item;
	root->rightchild = bt1.root;
	root->leftchild = bt2.root;
}
template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& t)
{
	root = copy(t.root);
}
template<class T>
TreeNode<T>* BinaryTree<T>::copy(TreeNode<T>* origNode)//递归拷贝树
{
	if (origNode)
		return new TreeNode<T>(origNode->data, copy(origNode->leftchild), copy(origNode->rightchild));
	else return 0;
}
template<class T>
void BinaryTree<T>::clear()
{
	stack<TreeNode<T>*> s;
	TreeNode<T>* currentNode = root;
	TreeNode<T>* temp = NULL;
	while (1)
	{
		while (currentNode)
		{
			s.push(currentNode);
			currentNode = currentNode->leftchild;
		}
		if (s.empty())
		{
			root = NULL;
			return;
		}
		currentNode = s.top();
		s.pop();
		temp = currentNode->rightchild;
		delete currentNode;
		currentNode = temp;
	}
}

template<class T>
bool BinaryTree<T>::isempty()
{
	if (!root)
		return true;
	else
		return false;
}
template<class T>
BinaryTree<T> BinaryTree<T>::Leftsubtree()
{
	BinaryTree p;
	p.root = root->leftchild;
	return p;
}
template<class T>
BinaryTree<T> BinaryTree<T>::Rightsubtree()
{
	BinaryTree p;
	p.root = root->rightchild;
	return p;
}
template<class T>
T BinaryTree<T>::rootdata()
{
	return root->data;
}
template<class T>
void BinaryTree<T>::display()
{
	if (!root)
	{
		cout << "空树！" << endl;
		return;
	}
	cout << rootdata() << " ";
	if (Leftsubtree().isempty() && Rightsubtree().isempty())
		return;
	else
	{
		cout << "(";
		if (!Leftsubtree().isempty())
			this->Leftsubtree().display();
		cout << " ";
		if (!Rightsubtree().isempty())
			this->Rightsubtree().display();
		cout << ")";
	}
}

template<class T>
void BinaryTree<T>::preorder()
{
	preorder(root);
}
template<class T>
void BinaryTree<T>::preorder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		cout << " " << currentNode->data << " ";
		preorder(currentNode->leftchild);
		preorder(currentNode->rightchild);
	}
}
template<class T>
void BinaryTree<T>::preiterator()
{
	stack<TreeNode<T>*> s;
	TreeNode<T>* currentNode = root;
	while (1)
	{
		while (currentNode)
		{
			cout << currentNode->data << " ";
			if (currentNode->rightchild)
				s.push(currentNode->rightchild);
			currentNode = currentNode->leftchild;
		}
		if (s.empty()) return;
		currentNode = s.top();
		s.pop();
	}
}

template<class T>
void BinaryTree<T>::inorder()
{
	inorder(root);
}
template<class T>
void BinaryTree<T>::inorder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		inorder(currentNode->leftchild);
		cout << " " << currentNode->data << " ";
		inorder(currentNode->rightchild);
	}
}
template<class T>
void BinaryTree<T>::initerator()
{
	stack<TreeNode<T>*> s;
	TreeNode<T>* currentNode = root;
	while (1)
	{
		while (currentNode)
		{
			s.push(currentNode);
			currentNode = currentNode->leftchild;
		}
		if (s.empty()) return;
		currentNode = s.top();
		s.pop();
		cout << currentNode->data << " ";
		currentNode = currentNode->rightchild;
	}
}

template<class T>
void BinaryTree<T>::postorder()
{
	postorder(root);
}
template<class T>
void BinaryTree<T>::postorder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		postorder(currentNode->leftchild);
		postorder(currentNode->rightchild);
		cout << " " << currentNode->data << " ";
	}
}
template<class T>
void BinaryTree<T>::postiterator()
{
	stack<TreeNode<T>*> s;
	TreeNode<T>* currentNode = root;
	TreeNode<T>* preNode = NULL;
	while (currentNode != NULL || !s.empty())
	{
		while (currentNode != NULL)
		{
			s.push(currentNode);
			currentNode = currentNode->leftchild;
		}
		currentNode = s.top();
		if (currentNode->rightchild == NULL || preNode == currentNode->rightchild)      //右子树为空或者右子树已经访问过
		{
			cout << currentNode->data << " ";
			s.pop();
			preNode = currentNode;
			currentNode = NULL;                                                         //待下次循环时取出父节点
		}
		else                                                                            //访问右树，但是不将上一结点弹出
		{
			currentNode = currentNode->rightchild;
			preNode = NULL;
		}
	}
}

template<class T>
void BinaryTree<T>::leveliterator()
{
	queue<TreeNode<T>*>q;
	TreeNode<T>* currentNode = root;
	while (currentNode)
	{
		cout << currentNode->data << " ";
		if (currentNode->leftchild) q.push(currentNode->leftchild);
		if (currentNode->rightchild)q.push(currentNode->rightchild);
		if (q.empty())return;
		currentNode = q.front();
		q.pop();
	}
}
