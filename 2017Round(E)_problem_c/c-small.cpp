#include<iostream>
#include<string>
#include<fstream>
#include<unordered_set>
#include<algorithm>
#include<set>
#include<vector>
#include<time.h>
#include<iomanip>

using namespace std;

double get_r(vector<int> list)
{
	double res;
	sort(list.begin(), list.end());
	res = (list[2] - list[0]) / 6.0;
	return res;
}

int main()
{
	string data_name = "C-small-practice.in";
	//string data_name = "sample.txt";
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

	int x, y, z;
	double r;
	vector<int> list;
	for (int case_id = 1; case_id <= T; case_id++)
	{
		list.clear();
		for (int i = 0; i < 3; i++)
		{
			data_file >> x >> y >> z;
			list.push_back(x);
		}
		r = get_r(list);
		cout << "Case #" << case_id << ": " << setiosflags(ios::fixed) << setprecision(10) <<r << endl;
		result_file << "Case #" << case_id << ": " << setiosflags(ios::fixed) << setprecision(10) << r << endl;
	}

	data_file.close();
	result_file.close();



	system("pause");
	return 0;
}

