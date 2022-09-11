//树的遍历
#include<iostream>
#include"tree.h"
using namespace std;

int main()
{
	BinaryTree<int> leaf1;
	BinaryTree<int> leaf2;
	int a[7] = { 1,2,3,4,5,6,7 };
	BinaryTree<int> node1(leaf1, a[6], leaf2);
	BinaryTree<int> node2(leaf1, a[5], leaf2);
	BinaryTree<int> node3(leaf1, a[4], leaf2);
	BinaryTree<int> node4(leaf1, a[3], leaf2);

	BinaryTree<int> node5(node1, a[2], node2);
	BinaryTree<int> node6(node3, a[1], node4);

	BinaryTree<int> tree(node5, a[0], node6);
	cout << "用表达式展示本树：\n";
	tree.display();
	cout << endl;
	cout << "先序递归遍历" << endl;
	tree.preorder();
	cout << endl;
	cout << "先序迭代遍历" << endl;
	tree.preiterator();
	cout << endl;
	cout << "中序递归遍历" << endl;
	tree.inorder();
	cout << endl;
	cout << "中序迭代遍历" << endl;
	tree.initerator();
	cout << endl;
	cout << "后序递归遍历" << endl;
	tree.postorder();
	cout << endl;
	cout << "后序迭代遍历" << endl;
	tree.postiterator();
	cout << endl;
	cout << "层序遍历" << endl;
	tree.leveliterator();
	cout << endl << "------------------------------------" << endl;;

	cout << "拷贝一个树" << endl;
	BinaryTree<int> tree1(tree);
	cout << "用表达式展示本树：\n";
	tree1.display();
	cout << endl << "------------------------------------" << endl;
	cout << "清除该树" << endl;
	tree.clear();
	tree.display();

	return 0;
}