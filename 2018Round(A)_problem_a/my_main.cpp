#include<iostream>
#include<string>
#include<fstream>
#include<unordered_set>
#include<algorithm>

//small & large  data;
using namespace std;

unsigned long long s2n(string sub)
{
	unsigned long long res_n = 0;
	int n = sub.size();
	for (int i = 0; i < n; i++)
	{
		res_n = res_n + (sub[n - 1 - i] - '0') *pow(10, i);
	}
	return res_n;
}

unsigned long long add(char pre, string sub_s, string sub)
{
	unsigned long long res1 = 0;
	string new_pre;
	if (pre == '9')
	{
		new_pre = "20";
	}
	else
	{
		new_pre = std::to_string(pre + 1 - '0');
	}
	unsigned long long new_n = atoi(new_pre.c_str()) * pow(10, sub_s.size());
	unsigned long long old_n = s2n(sub);
	res1 = new_n - old_n;
	return res1;
}

unsigned long long substract(char pre, string sub_s, string sub)
{
	unsigned long long res2 = s2n(sub_s) + 1;
	for (int i = 0; i < sub_s.size(); i++)
	{
		res2 = res2 + pow(10, i);
	}
	return res2;
}

unsigned long long minimal_times(unsigned long long n)
{
	unsigned long long res = 0;

	string s = std::to_string(n);

	int id = s.size();
	int temp;
	for (int i = 0; i < s.size(); i++)
	{
		temp = s[i] - '0';
		if (temp % 2 == 1)
		{
			id = i;
			break;
		}
	}
	if (id == s.size())
	{
		return 0;
	}
	char pre = s[id];
	string sub_s = s.substr((id + 1));
	string sub = s.substr(id);
	unsigned long long res1 = add(pre, sub_s, sub);
	unsigned long long res2 = substract(pre, sub_s, sub);


	res = res1 < res2 ? res1 : res2;
	
	return res;
}



int main()
{
	string data_name = "A-large-practice.in";
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
	
	unsigned long long N;
	unsigned long long count = 0;

	for (int case_id = 1; case_id <= T; case_id++)
	{
		data_file >> N;
		count = minimal_times(N);
		cout << "Case #" << case_id << ": " << count << endl;
		result_file << "Case #" << case_id << ": " << count << endl;
	}

	data_file.close();
	result_file.close();



	system("pause");
	return 0;
}

