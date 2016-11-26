#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA10071");
	t->begin();
	int v, tm;
	while (cin >> v >> tm)
	{
		cout << v*tm*2 << endl;
	}
	return 0;
}