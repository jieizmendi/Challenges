#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in","r",stdin);
	int k;
	string str;
	cin >> str >> k;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			cout << (char)(((str[i] - 65 + k) % (90 - 64)) + 65);
		else if (str[i] >= 97 && str[i] <= 122)
			cout << (char)(((str[i] - 97 + k) % (122 - 96)) + 97);
		else if (str[i] >= 48 && str[i] <= 57)
			cout << (char)(((str[i] - 48 + k) % (57 - 47)) + 48);
		else
			cout << str[i];
	}
	cout << endl;
	return 0;
}