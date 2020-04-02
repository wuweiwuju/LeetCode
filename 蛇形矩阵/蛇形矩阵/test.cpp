#include<iostream>
using namespace std;

const int N = 100;
int n, m;
int d[N][N] = { 0 };
int temp = 0;

int main()
{
	cin >> n >> m;
	int left = 0, right = m - 1;
	int up = 0, down = n - 1;
	while (left <= right && up <= down)
	{
		for (int i = left; i <= right; ++i)
		{
			++temp;
			d[up][i] = temp;
		}
		for (int i = up + 1; i <= down; ++i)
		{
			++temp;
			d[i][right] = temp;
		}
		if (up >= down)
			break;
		for (int i = right - 1; i >= left; --i)
		{
			++temp;
			d[down][i] = temp;
		}
		if (left >= right)
			break;
		for (int i = down - 1; i >= up + 1; --i)
		{
			++temp;
			d[i][left] = temp;
		}
		++up, --right, --down, ++left;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}