//NΪ����λ�������
#include<iostream>
using namespace std;
#define N 4
void Subset(int a[], int n, int len)
{
	if (n == 0)                     //nΪ0ʱ��˵��ĳ�εݹ��������������������
	{
		for (int i = 0; i < len; i++)
			cout << a[i] << " ";
		cout << endl;
		delete[] a;
		return;
	}
	else
	{
		for (int j = 0; j <= 1; j++)     //1��ʾֻ��0,1����ѡ������j=0ʱ�޸ģ�1ʱ���޸ģ��൱������
		{
			int* copy = new int[len];
			for (int i = 0; i < len; i++)//����ԭ����
				copy[i] = a[i];

			if (j == 0)                 //��������
				copy[n - 1] = 0;
			Subset(copy, n - 1, len);   //�Ӻ���ǰ�������룬���еݹ�
		}
	}
}

int main()
{
	int a[N];
	for (int i = 0; i < N; i++)
		a[i] = 1;
	Subset(a, N, N);
	return 0;
}