//�鿨��һ�������ڲ��ĵ���Ϸ��������һ�ֳ鿨��ʽ���������£�
//
//��ʼ��ֻ��һ�γ鿨���ᡣÿ�γ鿨�˷�һ�γ鿨���ᣬ���һ�ſ�Ƭ�����ſ�Ƭ�����������֣���һ�����ִ������ܻ�õ�Ǯ���ڶ������ִ������ܻ�õĶ���鿨����������ĳ鿨�����ǿ����ۼƵġ�
//
//���ڣ���֪���˿�Ƭ�����������еĿ�Ƭ�ϵ����֣��Լ����п�Ƭ��˳����ֻ��Ҫ����һ�ֳ鿨˳��ʹ�����ܻ��Ǯ����ࡣ
//
//5
//0 2
//1 1
//1 0
//1 0
//2 0

//���  4

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
