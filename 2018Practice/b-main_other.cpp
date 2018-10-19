#include<iostream>
#include<string>
#include<fstream>
#include<unordered_set>
#include<algorithm>
#include<set>

using namespace std;



bool kth(long long k, long long mid) {
	if (mid <= 1 || k == mid)
		return false;

	k = mid - (k - mid);
	mid = log2(k);
	mid = exp2(mid);
	return !kth(k, mid);
}

int get_k(long long k)
{
	long long mid = log2(k);
	mid = exp2(mid);
	if (kth(k, mid))
		return 1;
	else
		return 0;
}


int main()
{

	string data_name = "B-large-practice.in";
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

	int c;
	long long k;
	for (int case_id = 1; case_id <= T; case_id++)
	{
		data_file >> k;
		c = get_k(k);
		cout << "Case #" << case_id << ": " << c << endl;
		result_file << "Case #" << case_id << ": " << c << endl;
	}

	data_file.close();
	result_file.close();


	system("pause");
	return 0;
}

