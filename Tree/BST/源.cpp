//������������(BST)�ĸ߶�
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
		cout << "����Ԫ�أ�key��" << k << ",x��" << x << endl;
		tree.Insert(k, x);
	}
	cout << "�ñ��ʽչʾ������\n";
	tree.display();
	cout << endl;
	cout << "����ʵ�ʸ߶�Ϊ��\n";
	int height = tree.H(tree.root);
	cout << height << endl;
	cout << "�����" << endl;
	tree.clear();
	tree.display();


	return 0;
}