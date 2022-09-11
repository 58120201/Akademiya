//���ı���
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
	cout << "�ñ��ʽչʾ������\n";
	tree.display();
	cout << endl;
	cout << "����ݹ����" << endl;
	tree.preorder();
	cout << endl;
	cout << "�����������" << endl;
	tree.preiterator();
	cout << endl;
	cout << "����ݹ����" << endl;
	tree.inorder();
	cout << endl;
	cout << "�����������" << endl;
	tree.initerator();
	cout << endl;
	cout << "����ݹ����" << endl;
	tree.postorder();
	cout << endl;
	cout << "�����������" << endl;
	tree.postiterator();
	cout << endl;
	cout << "�������" << endl;
	tree.leveliterator();
	cout << endl << "------------------------------------" << endl;;

	cout << "����һ����" << endl;
	BinaryTree<int> tree1(tree);
	cout << "�ñ��ʽչʾ������\n";
	tree1.display();
	cout << endl << "------------------------------------" << endl;
	cout << "�������" << endl;
	tree.clear();
	tree.display();

	return 0;
}