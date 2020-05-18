class Solution {
public:
	vector<string> res;
	vector<string> letterCasePermutation(string S) {
		dfs(S, 0);
		return res;
	}
	void dfs(string S, int u)
	{
		if (u == S.size())
		{
			res.push_back(S);
			return;
		}

		dfs(S, u + 1);
		if (S[u] >= 'A')
		{
			S[u] ^= 32;
			dfs(S, u + 1);
		}
	}
};