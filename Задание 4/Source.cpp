#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct st
{
	int key;
	string s;
};

int main()
{
	int n;
	cin >> n;
	vector<st>arr(n);
	for (int i = 0; i < n; ++i)
	{
		st t;
		cin >> t.key;
		cin >> t.s;
		arr.push_back(t);
	}
	//сортировка
	int l = 0, r = n - 1;
	while (l < r)
	{
		while (arr[l].key != 1 && l < r) ++l;
		while (arr[r].key != 0 && l < r) --r;
		if (l < r)
		{
			swap(arr[l], arr[r]);
			++l;
			--r;
		}
	}
}