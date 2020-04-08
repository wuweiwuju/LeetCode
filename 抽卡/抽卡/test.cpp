//抽卡是一类类似于博弈的游戏。现在有一种抽卡方式，描述如下：
//
//初始你只有一次抽卡机会。每次抽卡浪费一次抽卡机会，获得一张卡片。这张卡片上有两个数字，第一个数字代表你能获得的钱，第二个数字代表你能获得的额外抽卡次数。额外的抽卡次数是可以累计的。
//
//现在，你知道了卡片的数量，所有的卡片上的数字，以及所有卡片的顺序。你只需要安排一种抽卡顺序，使得你能获得钱数最多。
//
//5
//0 2
//1 1
//1 0
//1 0
//2 0

//输出  4

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxMoney(vector<pair<int, int>>& arr, int count, int n)
{
	if (count <= 0)
		return 0;
	vector<pair<int, int>> temp(n);
	for (int i = 0; i < arr.size(); ++i) {
		temp[i].first = arr[i].second;
		temp[i].second = arr[i].first;
	}
	sort(temp.begin(), temp.end()), reverse(temp.begin(), temp.end());
	int sum = 0;
	int i = 0;
	for (i = 0; i < n; ++i) {
		if (temp[i].first == 0)
			break;
		sum += temp[i].second;
		count += temp[i].first;
		--count;
	}
	while (count--) {
		sum += temp[i++].second;
	}
	return sum;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	int count = 1;
	int ret = maxMoney(arr, count, n);
	cout << ret << endl;

	return 0;
}
