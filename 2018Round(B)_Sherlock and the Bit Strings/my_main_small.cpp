#include<iostream>
#include<string>
#include<fstream>
#include<vector>

//small data;
using namespace std;

string vec_string(vector<int> v)
{
	string s = "";
	for (int i = 0; i < v.size(); i++)
	{
		s = s + std::to_string(v[i]);
	}
	return s;
}

vector<int> ten2binary(unsigned long long p)
{
	vector<int> res;
	unsigned long long yushu, shang = p;
	while (shang)
	{
		yushu = shang % 2;
		res.push_back(yushu);
		shang = shang / 2;
	}
	return res;
}

string find_p_th(vector<int> base, vector<int> sign, unsigned long long p)
{
	if (p == 1)
	{
		return vec_string(base);
	}
	vector<int> binary_p = ten2binary((p - 1));
	int t = 0;
	int n = base.size();
	for (int i = n - 1; i >= 0; i--)
	{
		if (t == binary_p.size())
		{
			return vec_string(base);
		}
		if (sign[i] == 0)
		{
			base[i] = binary_p[t];
			t = t + 1;
		}
	}
	return vec_string(base);
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
	
	int N, K, A, B, C;
	unsigned long long P;
	vector<int> base, sign;
	string res;
	for (int case_id = 0; case_id < T; case_id++)
	{
		base.clear();
		sign.clear();
		data_file >> N >> K >> P;
		for (int n_i = 0; n_i < N; n_i++)
		{
			base.push_back(0);
			sign.push_back(0);
		}
		for (int k_i = 0; k_i < K; k_i++)
		{
			data_file >> A >> B >> C;
			base[A - 1] = C;
			sign[A - 1] = 1;
		}
		res = find_p_th(base, sign, P);
		cout << "Case #" << (case_id + 1) << ": " << res << endl;
		result_file << "Case #" << (case_id + 1) << ": " << res << endl;
	}

	system("pause");
	return 0;
}

