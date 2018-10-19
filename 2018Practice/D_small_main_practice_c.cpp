#include<iostream>
#include<string>
#include<fstream>
#include<unordered_set>
#include<algorithm>
#include<set>


using namespace std;


vector<long long> get_sum(vector<vector<int>> query, vector<int> list)
{
	vector<long long> res;

	vector<long long> new_list;
	int len = list.size();
	long long sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum = 0;
		for (int j = i; j < len; j++)
		{
			sum = sum + list[j];
			new_list.push_back(sum);
		}
	}

	sort(new_list.begin(), new_list.end());

	for (int i = 0; i < query.size(); i++)
	{
		sum = 0;

		for (int j = query[i][0]; j <= query[i][1]; j++)
		{
			sum = sum + new_list[j-1];
		}
		res.push_back(sum);
	}



	return res;
}



int main()
{

	string data_name = "D-small-practice.in";
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

	vector<long long> res;
	vector<int> list;
	vector<vector<int>> query;
	vector<int> query_i;
	int N, Q, temp, left, right;
	for (int case_id = 1; case_id <= T; case_id++)
	{
		list.clear();
		query.clear();
		data_file >> N >> Q;
		for (int i = 0; i < N; i++)
		{
			data_file >> temp;
			list.push_back(temp);
		}
		for (int i = 0; i < Q; i++)
		{
			query_i.clear();
			data_file >> left >> right;
			query_i.push_back(left);
			query_i.push_back(right);
			query.push_back(query_i);
		}
		res = get_sum(query, list);
		cout << "Case #" << case_id << ": " << endl;
		result_file << "Case #" << case_id << ": " << endl;
		for (int i = 0; i < Q; i++)
		{
			cout << res[i] << endl;
			result_file << res[i] << endl;
		}
	}

	data_file.close();
	result_file.close();


	system("pause");
	return 0;
}

