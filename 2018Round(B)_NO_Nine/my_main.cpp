#include<iostream>
#include<string>
#include<fstream>

//small data;
using namespace std;

long long int find_legal(long long int left, long long int right)
{
	string i_s;
	long long int res = 0;
	for (long long i = left; i <= right; i++)
	{
		i_s = std::to_string(i);
		if ((i % 9 == 0) || (i_s.find('9') != string::npos))
		{
			continue;
		}
		res = res + 1;
	}
	return res;
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
	long long int left, right, count;
	
	for (int case_id = 0; case_id < T; case_id++)
	{
		data_file >> left >> right;
		count = find_legal(left, right);
		cout << "Case #" << (case_id + 1) << ": " << count << endl;
		result_file << "Case #" << (case_id + 1) << ": " << count << endl;
	}


	system("pause");
	return 0;
}

