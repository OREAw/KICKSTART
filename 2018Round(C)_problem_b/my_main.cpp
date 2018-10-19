#include<iostream>
#include<vector>
#include<fstream>
#include<unordered_set>
#include<map>


//只适用于小数据， 大数据会超时，
//第一步，将所有的边和相连顶点选出；
//第二步，求解线性方程，b = 3...；
//第三步，判断线性方程组的解是否能构成凸边形
using namespace std;
void helper(int left, int right, int k, vector<int> &tmpres, vector<vector<int> >&res)
{
	if (right - left + 1 < k)return;
	if (k == 0)
	{
		res.push_back(tmpres);
		return;
	}
	//选择left
	tmpres.push_back(left);
	helper(left + 1, right, k - 1, tmpres, res);
	tmpres.pop_back();
	//不选择left
	helper(left + 1, right, k, tmpres, res);
}
vector<vector<int> > combine(int n, int k) {
	vector<vector<int> >res;
	vector<int>tmpres;
	helper(1, n, k, tmpres, res);
	return res;
}

int find_res(vector<vector<int>> res, vector<vector<int>> sticks)
{
	int r = 0;
	int sum = 0;
	int max = INT_MIN;
	unordered_set<int> set;
	int j, t;
	for (int i = 0; i < res.size(); i++)
	{
		set.clear();
		sum = 0;
		max = INT_MIN;
		for (t = 0; t < res[i].size(); t++)
		{
			j = res[i][t] - 1;
			if ((set.count(sticks[j][1]) == 0) && (set.count(sticks[j][0]) == 0))
			{
				set.insert(sticks[j][1]);
				set.insert(sticks[j][0]);
				sum = sum + sticks[j][2];
				if (max < sticks[j][2])
				{
					max = sticks[j][2];
				}
			}
			else
			{
				break;
			}


		}
		if (((set.size() / 2) == res[i].size()) && (sum - max > max))
		{
			r = r + 1;
		}
	}
	return r;
}
int find_convex(int nodes, vector<vector<int>> square)
{
	int counts = 0;
	vector<vector<int>> sticks;//x, y, len
	vector<int> vec;
	for (int i = 0; i < nodes; i++)
	{
		for (int j = i + 1; j < nodes; j++)
		{
			if (square[i][j] > 0)
			{
				vec.push_back(i);
				vec.push_back(j);
				vec.push_back(square[i][j]);
				sticks.push_back(vec);
				vec.clear();
			}
		}
	}

	int n = sticks.size();
	int temp;
	for (int i = 3; i <= sticks.size(); i++)
	{
		vector<vector<int>> res;
		res = combine(n, i);
		temp = find_res(res, sticks);
		if (temp == 0)
		{
			break;
		}
		else
		{
			counts = counts + temp;
		}

	}
	return counts;
}



int main()
{
	string data_name = "data.txt";
	string result_name = "result.txt";

	ifstream data_file;
	ofstream result_file;
	data_file.open(data_name, ios::in);
	if (!data_file.is_open())
	{
		cout << "cannot open this file" << endl;
	}
	result_file.open(result_name);
	if (!result_file.is_open())
	{
		cout << "cannot open this file" << endl;
	}

	int T; // the number of cases
	data_file >> T;

	vector<vector<int>> square;
	vector<int> vec;
	int nodes;
	int temp;
	int counts;
	for (int case_id = 0; case_id < T; case_id++)
	{
		square.clear();
		data_file >> nodes;
		for (int x_i = 0; x_i < nodes; x_i++)
		{
			vec.clear();
			for (int y_i = 0; y_i < nodes; y_i++)
			{
				data_file >> temp;
				vec.push_back(temp);
			}
			square.push_back(vec);
		}
		counts = find_convex(nodes, square);
		result_file << "Case #" << (case_id + 1) << ": " << counts << endl;
		cout << "Case #" << (case_id + 1) << ": " << counts << endl;
	}


	system("pause");
	return 0;
}

