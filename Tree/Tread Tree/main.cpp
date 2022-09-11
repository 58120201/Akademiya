#include<iostream>
#include"ThreadTree.h"
using namespace std;

int main()
{
	ThreadTree<int> leaf1;
	ThreadTree<int> leaf2;
	int a[7] = { 1,2,3,4,5,6,7 };
	ThreadTree<int> node7(leaf1, a[6], leaf2);
	ThreadTree<int> node6(leaf1, a[5], leaf2);
	ThreadTree<int> node5(leaf1, a[4], leaf2);
	ThreadTree<int> node4(leaf1, a[3], leaf2);
	ThreadTree<int> node3(leaf1, a[2], leaf2);
	ThreadTree<int> node2(leaf1, a[1], leaf2);
	ThreadTree<int> node1(leaf1, a[0], leaf2);
	int x = -1;
	ThreadTree<int> tree(node1, x, leaf1);

	tree.InsertLeft(tree.root, node1.root);

	node1.InsertLeft(node1.root, node2.root);
	node1.InsertRight(node1.root, node3.root);

	node3.InsertLeft(node3.root, node6.root);
	node3.InsertRight(node3.root, node7.root);
	node3.InsertLeft(node2.root, node4.root);
	node3.InsertRight(node2.root, node5.root);


	cout << "展示本树：\n";
	tree.display();
	cout << endl << "------------------------------------" << endl;;

	cout << "输入将插入结点的data\n";
	cin >> x;
	ThreadTree<int> anode(leaf1, x, leaf2);
	tree.InsertRight(node7.root, anode.root);
	cout << "现在树成了这样：\n";
	tree.display();

	cout << endl << "------------------------------------" << endl;
	cout << "清除该树" << endl;
	tree.clear();
	tree.display();


	return 0;
}