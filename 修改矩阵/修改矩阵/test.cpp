#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

int n, m;
typedef pair<int, int> PII;

int main()
{
	cin >> n >> m;
	unordered_map<int, int> as, bs;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int x = 0;
			cin >> x;
			if ((i + j) % 2 != 0)    as[x]++;
			else     bs[x]++;
		}
	}

	vector<PII> temp1, temp2;
	for (auto item : as) temp1.push_back({ item.second, item.first });
	for (auto item : bs) temp2.push_back({ item.second, item.first });

	sort(temp1.begin(), temp1.end()), reverse(temp1.begin(), temp1.end());
	sort(temp2.begin(), temp2.end()), reverse(temp2.begin(), temp2.end());

	int res = 0;
	for (int i = 0; i < 2 && i < temp1.size(); ++i)
	{
		for (int j = 0; j < 2 && j < temp2.size(); ++j)
		{
			if (temp1[i].second == temp2[j].second)
				res = max(res, max(temp1[i].first, temp2[j].first));
			else
				res = max(res, temp1[i].first + temp2[j].first);
		}
	}

	if (temp1.empty())   res = temp2[0].first;

	if (temp2.empty())   res = temp1[0].first;

	cout << n * m - res << endl;
	return 0;
}