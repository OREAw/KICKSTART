#include<iostream>
#include<string>
#include<fstream>
#include<unordered_set>
#include<algorithm>
#include<set>


using namespace std;


string order_flights(vector<vector<string>> flights)
{
	string s = "";
	s = s + flights[0][0] + "-" + flights[0][1];
	flights.erase(flights.begin());
	string head = s.substr(0, 3);
	string end = s.substr(s.size() - 3, 3);
	int i = 0;
	while (!flights.empty())
	{
		if (head == flights[i][1])
		{
			s = flights[i][0] + "-" + flights[i][1] + " "+ s;
		    head = s.substr(0, 3);
			flights.erase(flights.begin() + i);
			i = 0;
			continue;
		}
		if (end == flights[i][0])
		{
			s = s + " " + flights[i][0] + "-" + flights[i][1];
			end = s.substr(s.size() - 3, 3);
			flights.erase(flights.begin() + i);
			i = 0;
			continue;
		}
		i = i + 1;
	}
	return s;
}




int main()
{

	string data_name = "C-large-practice.in";
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

	vector<vector<string>> flights;
	vector<string> one;
	int N;
	string start, end;
	string itinerary;
	for (int case_id = 1; case_id <= T; case_id++)
	{
		flights.clear();
		data_file >> N;
		for (int i = 0; i < N; i++)
		{
			one.clear();
			data_file >> start >> end;
			one.push_back(start);
			one.push_back(end);
			flights.push_back(one);
		}
		itinerary = order_flights(flights);
		cout << "Case #" << case_id << ": " << itinerary << endl;
		result_file << "Case #" << case_id << ": " << itinerary << endl;


	}

	data_file.close();
	result_file.close();


	system("pause");
	return 0;
}

