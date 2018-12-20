#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define Ho

using namespace std;

#ifndef Hor
int main()
{
	string s, t; // входные данные

	cout << "Enter substring\n";
	cin >> s;
	cout << "Enter string\n";
	cin >> t;
				 // считаем все степени p
	const int p = 31;
	vector<long long> p_pow(t.length());
	p_pow[0] = 1;
	for (size_t i = 1; i < p_pow.size(); ++i)
		p_pow[i] = p_pow[i - 1] * p;

	// считаем хэши от всех префиксов строки T
	vector<long long> h(t.length());
	for (size_t i = 0; i < t.length(); ++i)
	{
		h[i] = (t[i] - 'a' + 1) * p_pow[i];//*pow(31,i);
		if (i!=0)  h[i] += h[i - 1];
	}

	// считаем хэш от строки S
	long long h_s = 0;
	for (size_t i = 0; i < s.length(); ++i)
		h_s += (s[i] - 'a' + 1) * p_pow[i];

	// перебираем все подстроки T длины |S| и сравниваем их
	for (size_t i = 0; i + s.length() - 1 < t.length(); ++i)
	{
		long long cur_h = h[i + s.length() - 1];
		if (i!=0)  cur_h -= h[i - 1];
		// приводим хэш к одной степени и сравниваем
		if (cur_h == h_s * p_pow[i])
			cout << i << ' ';
	}
	system("pause");
}
#endif


#ifdef Hor


int main()
{
	string tem, s;
	cout << "string\n";
	cin >> s;
	cout << "template\n";
	cin >> tem;
	vector<int>offset(128, tem.size());
	for (int i = tem.size() - 2; i >= 0; --i)
		if (offset[tem[i]] == tem.size()) offset[tem[i]] = tem.size() - i - 1;//kaef

	for (int i = 0; i < s.size();)//it's okay
	{
		char key=s[i+tem.size()-1];
		for (int j = tem.size() - 1; j >= 0; --j)
		{
			if (s[i + j] != tem[j]) 
				break;
			if (j == 0)
				cout << i << endl;
		}
		i += offset[key];
	}
	system("pause");
}
#endif