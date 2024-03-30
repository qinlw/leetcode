#include"leetcode_917.hpp"

int main()
{
	Solution t;
	string s[] = { "ab-cd", "a-bC-dEf-ghIj", "Test1ng-Leet=code-Q!", "--af--fj-dsasokl"};
	string str = "ab-cd";
	cout << str << endl << t.reverseOnlyLetters(str) << endl << endl;
	for (auto e : s)
	{
		cout << e << endl << t.reverseOnlyLetters(e) << endl;
		cout << endl;
	}
}