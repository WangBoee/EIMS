#include <iostream>
void print(const string& str)
{
	for (auto i : str)
	{
		cout << i;
		Sleep(35);
	}
}