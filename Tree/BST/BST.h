#pragma once
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
template<class T>
class BST;
template<class T>
class TreeNode
{
	friend class BST<T>;
private:
	int key;
	T data;
	TreeNode<T>* leftchild;
	TreeNode<T>* rightchild;
public:
	TreeNode<T>(int k, T e);
};
template<class T>
TreeNode<T>::TreeNode(int k, T e)
{
	key = k;
	data = e;
	leftchild = rightchild = NULL;
}


template<class T>
class BST
{
public:
	TreeNode<T>* root;
public:
	BST();
	bool isempty();
	BST(BST<T>& bt1, T& item, BST<T>& bt2);
	BST<T> Leftsubtree();
	BST<T> Rightsubtree();
	T rootdata();
	void display();
	void clear();

	void inorder();                                    //中序递归
	void inorder(TreeNode<T>* currentNode);

	TreeNode<T>Get(const int& k);
	TreeNode<T>Get(TreeNode<T>* p, const int& k);

	void Insert(int k, T e);

	int H(TreeNode<T>* t);
};
template<class T>
BST<T>::BST()
{
	root = NULL;
}
template<class T>
bool BST<T>::isempty()
{
	if (root == NULL)
		return true;
	else
		return false;
}
template<class T>
BST<T>::BST(BST<T>& bt1, T& item, BST<T>& bt2)
{
	root = new TreeNode<T>;
	root->data = item;
	root->rightchild = bt1.root;
	root->leftchild = bt2.root;
}
template<class T>
BST<T> BST<T>::Leftsubtree()
{
	BST p;
	p.root = root->leftchild;
	return p;
}
template<class T>
BST<T> BST<T>::Rightsubtree()
{
	BST p;
	p.root = root->rightchild;
	return p;
}
template<class T>
T BST<T>::rootdata()
{
	return root->data;
}
template<class T>
void BST<T>::display()
{
	if (!(this->root))
	{
		cout << "空树！" << endl;
		return;
	}
	cout << rootdata() << " ";
	if (Leftsubtree().isempty() && Rightsubtree().isempty())
		return;
	cout << "(";
	if (!Leftsubtree().isempty())
		this->Leftsubtree().display();
	cout << " ";
	if (!Rightsubtree().isempty())
		this->Rightsubtree().display();
	cout << ")";
}
template<class T>
void BST<T>::clear()
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
void BST<T>::inorder()
{
	inorder(root);
}
template<class T>
void BST<T>::inorder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		inorder(currentNode->leftchild);
		cout << " " << currentNode->data << " ";
		inorder(currentNode->rightchild);
	}
}

template<class T>
TreeNode<T> BST<T>::Get(const int& k)
{
	return Get(root, k);
}
template<class T>
TreeNode<T> BST<T>::Get(TreeNode<T>* p, const int& k)
{
	if (!p) return 0;
	if (k < p->key)return Get(p->leftchild, k);
	if (k > p->key)return Get(p->rightchild, k);
	return &p->data;
}

template<class T>
void BST<T>::Insert(int k, T e)
{
	TreeNode<T>* p = root, * pp = 0;
	while (p)
	{
		pp = p;
		if (k < p->key)p = p->leftchild;
		else if (k > p->key)p = p->rightchild;
		else
		{
			p->data = e;
			return;
		}
	}
	p = new TreeNode<T>(k, e);
	if (root)
		if (k < pp->key)
			pp->leftchild = p;
		else
			pp->rightchild = p;
	else
		root = p;
}

template<class T>
int BST<T>::H(TreeNode<T>* t)            //递归方法计算树高度
{
	if (t)
	{
		int lefth = H(t->leftchild) + 1;
		int righth = H(t->rightchild) + 1;
		return max(lefth, righth);
	}
	else
		return 0;
}