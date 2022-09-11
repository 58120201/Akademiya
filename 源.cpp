//KMP算法
#include<iostream>
#include<string>
using namespace std;
#define N 9
class String
{
	char str[N];
public:
	int f[N];
	String(char str0[N]);
	int Length();
	void failure();
	int Find(String pat);
};
String::String(char str0[N])
{
	strcpy_s(str, strlen(str0) + 1, str0);
	for (int i = 0; i < N; i++)
		f[i] = 0;
}
int String::Length()
{
	int i = 0;
	while (*(str + i))
		i++;
	return i;
}
void String::failure()
{
	int lengthP = Length();
	f[0] = -1;
	for (int j = 1; j < lengthP; j++)
	{
		int i = f[j - 1];
		while (*(str + j) != *(str + i + 1) && (i >= 0))
			i = f[i];
		if (*(str + j) == *(str + i + 1))
			f[j] = i + 1;
		else
			f[j] = -1;
	}
}
int String::Find(String pat)
{
	char* p = pat.str, * q = this->str;
	int i = 0;
	if (*p && *q)
	{
		while (i <= this->Length() - pat.Length())
		{
			if (*p++ == *q++)
			{
				if (!*p)
					return i;
			}
			else { i++; q = str + i; p = pat.str; }
		}
	}
	return -1;
}
int main()
{
	char x[] = "bacin";
	String pat(x);
	pat.failure();
	for (int i = 1; i < N; i++)
		cout << "f[" << i << "]=" << pat.f[i] << endl;
	char y[] = "bviabacine";
	String str(y);
	cout << "在第" << str.Find(pat) + 1 << "位找到目标模式！";
	return 0;
}