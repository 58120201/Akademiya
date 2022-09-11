#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<stack>
using namespace std;

template<class T>
class ThreadTree;
template<class T>
class ThreadNode
{
	friend class ThreadTree<T>;
private:
	bool leftThread;
	ThreadNode<T>* leftchild;
	T data;
	ThreadNode<T>* rightchild;
	bool rightThread;
public:
	ThreadNode<T>(T x = 0, ThreadNode<T>* bt1 = NULL, ThreadNode<T>* bt2 = NULL);
};
template<class T>
ThreadNode<T>::ThreadNode(T x, ThreadNode<T>* bt1, ThreadNode<T>* bt2)
{
	data = x;
	leftchild = bt1;
	rightchild = bt2;
	rightThread = leftThread = false;
}


template<class T>
class ThreadTree
{
public:
	ThreadNode<T>* root;
public:
	ThreadTree();
	ThreadTree(ThreadTree<T>& bt1, T& item, ThreadTree<T>& bt2);
	void clear();

	bool isempty();
	ThreadTree<T> Leftsubtree();
	ThreadTree<T> Rightsubtree();
	T rootdata();

	void display();

	void InsertRight(ThreadNode<T>* s, ThreadNode<T>* r);
	void InsertLeft(ThreadNode<T>* s, ThreadNode<T>* r);
	ThreadNode<T>* Inordersucc(ThreadNode<T>* r);
};
template<class T>
ThreadTree<T>::ThreadTree()
{
	root = NULL;
}
template<class T>
ThreadTree<T>::ThreadTree(ThreadTree<T>& bt1, T& item, ThreadTree<T>& bt2)
{
	root = new ThreadNode<T>;
	root->data = item;
	root->rightchild = bt1.root;
	root->leftchild = bt2.root;
	root->leftThread = root->rightThread = true;
}

template<class T>
void ThreadTree<T>::clear()
{
	stack<ThreadNode<T>*> s;
	ThreadNode<T>* currentNode = root->leftchild;
	ThreadNode<T>* temp = NULL;
	if (!root->leftchild)
	{
		cout << "¿ÕÊ÷£¡" << endl;
		return;
	}
	ThreadNode<T>* p = this->Inordersucc(root);
	while (p != root)
	{
		if (temp == root->leftchild)
			temp = this->Inordersucc(root->leftchild);
		else
			temp = p->rightchild;
		delete p;
		p = temp;
	}
	delete p;
	root = NULL;
}

template<class T>
bool ThreadTree<T>::isempty()
{
	if (!root)
		return true;
	else
		return false;
}
template<class T>
ThreadTree<T> ThreadTree<T>::Leftsubtree()
{
	ThreadTree p;
	p.root = root->leftchild;
	return p;
}
template<class T>
ThreadTree<T> ThreadTree<T>::Rightsubtree()
{
	ThreadTree p;
	p.root = root->rightchild;
	return p;
}
template<class T>
T ThreadTree<T>::rootdata()
{
	return root->data;
}

template<class T>
void ThreadTree<T>::display()
{
	if (!root)
	{
		cout << "¿ÕÊ÷£¡" << endl;
		return;
	}
	ThreadNode<T>* p = this->Inordersucc(root);
	while (p != root)
	{
		cout << p->data << " ";
		if (p == root->leftchild)
			p = this->Inordersucc(root->leftchild);
		else
			p = p->rightchild;
	}
}

template<class T>
void ThreadTree<T>::InsertRight(ThreadNode<T>* s, ThreadNode<T>* r)
{
	r->rightchild = s->rightchild;
	r->rightThread = s->rightThread;
	r->leftchild = s;
	r->leftThread = true;
	s->rightchild = r;
	s->rightThread = false;
	if (!r->rightThread)
	{
		ThreadNode<T>* temp = Inordersucc(r);
		temp->leftchild = r;
	}
}
template<class T>
void ThreadTree<T>::InsertLeft(ThreadNode<T>* s, ThreadNode<T>* r)
{
	if (s->leftThread == false)
		s->leftchild = s;
	r->leftchild = s->leftchild;
	r->leftThread = s->leftThread;
	r->rightchild = s;
	r->rightThread = true;
	s->leftchild = r;
	s->leftThread = false;
	if (!r->leftThread)
	{
		ThreadNode<T>* temp = Inordersucc(r);
		temp->rightchild = r;
	}
}
template<class T>
ThreadNode<T>* ThreadTree<T>::Inordersucc(ThreadNode<T>* r)
{
	ThreadNode<T>* currentNode = r;
	if (!currentNode)
		return 0;
	if (currentNode->leftThread);
	currentNode = currentNode->rightchild;
	while (currentNode->leftThread == 0)
		currentNode = currentNode->leftchild;
	return currentNode;
}

