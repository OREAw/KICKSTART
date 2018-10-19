#include<iostream>
#include<string>
#include<fstream>
#include<unordered_set>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;


long sum_to(long a[], long b[], int N, long lo, long hi, long index) {
	long mid, lt, eq;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		lt = eq = 0;

		int j = 0;
		for (int i = 1; i <= N; ++i) {
			while (j < i && a[i] - a[j] > mid)
				++j;
			if (i != j)
				if (a[i] - a[j] == mid) {
					++eq;
					lt += i - 1 - j;
				}
				else
					lt += i - j;
		}

		if (lt + eq < index)
			lo = mid + 1;
		else if (lt > index)
			hi = mid - 1;
		else if (lt + eq >= index)
			break;
	}

	long re = (index - lt) * mid;
	int j = 0;
	for (int i = 1; i <= N; ++i) {
		while (j < i && a[i] - a[j] > mid)
			++j;
		if (i != j)
			if (a[i] - a[j] == mid)
				re += (i - j - 1) * a[i] - (b[i - 1] - b[j]);
			else
				re += (i - j) * a[i] - (b[i - 1] - b[j - 1]);
	}
	return re;
}

long get_sums(vector<int> list, int N, int index)
{
	long total = 0, lo = 100;
	long a[200001] = {0}, b[200001] = {};
	for (int n = 1; n <= N; ++n) 
	{
		a[n] = list[n - 1];
		if (lo > a[n])
			lo = a[n];
		a[n] += a[n - 1];
		total += a[n];
		b[n] = total;
	}
	return sum_to(a, b, N, lo, total, index);

}




int main()
{

	string data_name = "D-large-practice.in";
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

	vector<int> array;
	int N, Q;
	int temp, left, right;
	long sum, sum1, sum2;

	for (int case_id = 1; case_id <= T; case_id++)
	{
		array.clear();
		data_file >> N >> Q;
		for (int i = 0; i < N; i++)
		{
			data_file >> temp;
			array.push_back(temp);
		}
		cout << "Case #" << case_id << ": " << endl;
		result_file << "Case #" << case_id << ": " << endl;
		for (int i = 0; i < Q; i++)
		{
			data_file >> left >> right;
			left = left - 1;
			sum1 = get_sums(array, N, left);
			sum2 = get_sums(array, N, right);
			sum = sum2 - sum1;
			result_file << sum << endl;
		}
	}

	data_file.close();
	result_file.close();


	system("pause");
	return 0;
}

