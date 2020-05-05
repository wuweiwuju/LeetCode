/*#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


int calcMinStaff() {
	int n = 0;
	cin >> n;
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	vector<vector<int>> array(n, vector<int>(2));
	for (int i = 0; i < array.size(); ++i)
		for (int j = 0; j < 2; ++j)
			cin >> array[i][j];

	int count = n;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (array[i][1] <= array[j][0]) {
				--count;
				break;
			}
		}
	}

	return count;

}


int main() {
	int res;


	res = calcMinStaff();
	cout << res << endl;

	return 0;

}*/

/*#include<iostream>
#include<vector>
#include<string>
using namespace std;
string compareWord(string temp, vector<string>& str)
{
	for (int i = 0; i < str.size(); ++i) {
		if (temp.size() <= str[i].size() + 2 &&
			temp.size() >= str[i].size() - 2) {
			if (temp.size() <= str[i].size() + 2) {
				int count = 0;
				for (int k = 0; k < temp.size(); ++k) {
					if (str[i].find(temp[k])) {
						count++;
					}
				}
				if (count >= str[i].size() - 2)
					return str[i];
			}
			else {
				int count = 0;
				for (int k = 0; k < temp.size(); ++k) {
					if (str[i].find(temp[k])) {
						count++;
					}
				}
				if (count >= str[i].size() - 1)
					return str[i];
			}
		}
	}
	return "a";
}
int main()
{
	vector<string> str{ "surprise", "happy", "ctrip", "travel", "wellcome","student","system","program","editor" };
	string temp;
	while (cin >> temp) {
		string ret = compareWord(temp, str);
		if (ret != "a")
			cout << ret << endl;
		else
			cout << "null" << endl;
	}
	return 0;
}*/
