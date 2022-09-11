//N为排列位数，输出
#include<iostream>
using namespace std;
#define N 4
void Subset(int a[], int n, int len)
{
	if (n == 0)                     //n为0时，说明某次递归结束，输出这种掩码组合
	{
		for (int i = 0; i < len; i++)
			cout << a[i] << " ";
		cout << endl;
		delete[] a;
		return;
	}
	else
	{
		for (int j = 0; j <= 1; j++)     //1表示只有0,1两种选择，所以j=0时修改，1时不修改，相当于掩码
		{
			int* copy = new int[len];
			for (int i = 0; i < len; i++)//复制原数列
				copy[i] = a[i];

			if (j == 0)                 //设置掩码
				copy[n - 1] = 0;
			Subset(copy, n - 1, len);   //从后向前设置掩码，进行递归
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