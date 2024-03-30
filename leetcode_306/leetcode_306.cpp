#include "leetcode_306.hpp"

// 1204124
// 000
// 012
// 121224036
// 112358
// 199100199
// 1203
// 1023

int main()
{
	Solution test;
	string num[] = { "112358", "000", "1204124", "199100199", "1002000020100", "0224610", "1011011111", "111122335588143", "1980198239625944", "007714", "90908080171700", "022460", "1230", "121224036", "1203", "1023", "12315018", "10110111110", "012"};
	string str = "1980198239625944";
	cout << test.isAdditiveNumber(str) << endl;
	for (auto e : num)
	{
		if (test.isAdditiveNumber(e))
		{
			cout << e << ":\t\t true" << endl;
		}
		else
		{
			cout << e << ":\t\t false" << endl;
		}
	}

	return 0;
}