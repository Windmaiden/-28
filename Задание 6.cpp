#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(string s)
{
	size_t n = s.length();
	vector<int> pi(n); // � i-� �������� (��� ������ i-1) ���������� ��������� �������� � ������ � ����� ��� �������� ����� i. 
						  // p[0]=0 ������, p[1]=1, ���� ���������� � ���� ���������� 
	for (size_t i = 1; i < n; ++i)
	{
		size_t j = pi[i - 1];
		while ((j > 0) && (s[i] != s[j])) // �� �����
			j = pi[j - 1];				// ����� ����� ������������ �������� (������� � ����������� ���������)
		if (s[i] == s[j]) // ����� 
			++j;
		pi[i] = j;
	}
	return pi;
}

int main()
{
	string s, fin;
	cin >> s >> fin;
	if (s.size() != fin.size())
	{
		cout << "false" << endl;
		system("pause");
		return 0;
	}
	vector<int>h = prefix_function(fin + "@" + s + s);
	for(int i=0;i<h.size();++i)
		if (h[i] == fin.size())
		{
			cout << "true" << endl;
			system("pause");
			return 0;
		}
	cout << "false" << endl;
			system("pause");
			return 0;
	

}