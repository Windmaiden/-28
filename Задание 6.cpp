#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(string s)
{
	size_t n = s.length();
	vector<int> pi(n); // в i-м элементе (его индекс i-1) количество совпавших символов в начале и конце для построки длины i. 
						  // p[0]=0 всегда, p[1]=1, если начинается с двух одинаковых 
	for (size_t i = 1; i < n; ++i)
	{
		size_t j = pi[i - 1];
		while ((j > 0) && (s[i] != s[j])) // не равны
			j = pi[j - 1];				// берем ранее рассчитанное значение (начиная с максимально возможных)
		if (s[i] == s[j]) // равны 
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