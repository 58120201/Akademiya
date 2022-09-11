//计算二叉查找树(BST)的高度
#include<iostream>
#include"BST.h"
using namespace std;
#define n 10

int main()
{
	srand(unsigned(time(0)));
	BST<char> tree;
	for (int i = 0; i < n; i++)
	{
		int k = rand() % n;
		char x = 'a' + rand() % 26;
		cout << "插入元素：key：" << k << ",x：" << x << endl;
		tree.Insert(k, x);
	}
	cout << "用表达式展示本树：\n";
	tree.display();
	cout << endl;
	cout << "树的实际高度为：\n";
	int height = tree.H(tree.root);
	cout << height << endl;
	cout << "清除树" << endl;
	tree.clear();
	tree.display();


	return 0;
}