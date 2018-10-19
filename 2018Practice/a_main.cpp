#include<iostream>
#include<string>
#include<fstream>
#include<unordered_set>
#include<algorithm>
#include<set>

using namespace std;
vector<int> find_city(vector<vector<int>> bus, vector<int> city)
{
	vector<int> res;
	int count;
	for (int i = 0; i < city.size(); i++)
	{
		count = 0;
		for (int j = 0; j < bus.size(); j++)
		{
			if ((city[i] >= bus[j][0]) && (city[i] <= bus[j][1]))
			{
				count++;
			}
		}
		res.push_back(count);
	}
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

	int N, P;
	vector<vector<int>> bus;
	vector<int> bus_i;
	vector<int> city;
	int city_i;
	vector<int> counts;

	for (int case_id = 1; case_id <= T; case_id++)
	{
		city.clear();
		bus_i.clear();
		bus.clear();
		data_file >> N;
		int a_i, b_i;
		for (int i = 0; i < N; i++)
		{
			bus_i.clear();
			data_file >> a_i >> b_i;
			bus_i.push_back(a_i);
			bus_i.push_back(b_i);
			bus.push_back(bus_i);
		}
		data_file >> P;
		
		for (int i = 0; i < P; i++)
		{
			data_file >> city_i;
			city.push_back(city_i);
		}
		counts = find_city(bus, city);
		cout << "Case #" << case_id << ": ";
		result_file << "Case #" << case_id << ": ";
		for (int i = 0; i < counts.size(); i++)
		{
			cout << counts[i] << " ";
			result_file << counts[i] << " ";
		}
		cout << endl;
		result_file << endl;
	}

	data_file.close();
	result_file.close();



	system("pause");
	return 0;
}

