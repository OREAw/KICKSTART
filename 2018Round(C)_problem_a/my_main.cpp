#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

//大小数据都适用
//第一步， 根据节点的度，进行循环不断将度为1的结点剔除，当再也找不到度为1的结点时，剩下的结点组成环路；
//第二步，将环路上的结点的距离设置为1，对不在环路上的结点进行距离计算，找到离其最近的结点，并将其从非环路结点集合中删除
//当非环路集合中结点为空时，结束，输出到文件中


void output_vector(int * v, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << (i % 10) << ",";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ",";
	}
	cout << endl;
}
void output_matrix(int ** v, int n)
{
	cout << 'x' << ",";
	for (int i = 0; i < n; i++)
	{
		cout << (i % 10) << ",";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ( i % 10 ) << ",";
		for (int j = 0; j < n; j++)
		{
			
			if (v[i][j] == 1)
			{
				cout << v[i][j] << ",";
			}
			else
			{
				cout << 0 << ",";
			}
			
		}
		cout << endl;
	}
	
}

void substract_d(vector<int> temp_v, int **net, int *d, int planets)
{
	for (int v_id = 0; v_id < temp_v.size(); v_id++)
	{
		for (int jj = 0; jj < planets; jj++)
		{
			if ((d[jj] > 0) && (net[temp_v[v_id]][jj] == 1))
			{
				d[jj] = d[jj] - 1;
			}
		}
	}
}

int * find_shortest_path(int planets, vector<int> rows, vector<int> cols)
{
	
	int **net = new int*[planets];
	int *d = new int[planets];
	int *dis = new int[planets];
	for (int ii = 0; ii < planets; ii++)
	{
		net[ii] = new int[planets];
		d[ii] = 0;
		dis[ii] = INT_MAX - 1;
	}
	
	for (int ii = 0; ii < rows.size(); ii++)
	{
		net[rows[ii]][cols[ii]] = 1;
		net[cols[ii]][rows[ii]] = 1;
		d[rows[ii]] = d[rows[ii]] + 1;
		d[cols[ii]] = d[cols[ii]] + 1;
	}
	//cout << "before:" << endl;
	//output_vector(d, planets);

	//cout << "net:" << endl;
	//output_matrix(net, planets);

	while (true)
	{
		vector<int> temp_v;
		for (int index = 0; index < planets; index++)
		{
			if (d[index] == 1)
			{
				d[index] = 0;
				temp_v.push_back(index);
			}
		}
		if (temp_v.empty())
		{
			break;
		}
		substract_d(temp_v, net, d, planets);
		//cout << "after:" << endl;
		//output_vector(d, planets);
	}
	//cout << "after:" << endl;
	//output_vector(d, planets);

	vector<int> circle;
	vector<int> others;
	for (int ii = 0; ii < planets; ii++)
	{
		if (d[ii] >= 2)
		{
			circle.push_back(ii);
			dis[ii] = 0;
		}
		else
		{
			others.push_back(ii);
		}
	}
	int min_dis;
	while (others.size() > 0)
	{
		for (int ii = 0; ii < others.size(); ii++)
		{
			min_dis = INT_MAX;
			for (int jj = 0; jj < planets; jj++)
			{
				if (net[others[ii]][jj] == 1)
				{
					if (min_dis >(dis[jj] + 1))
					{
						min_dis = dis[jj] + 1;
					}
				}
			}
			if (min_dis < INT_MAX)
			{
				dis[others[ii]] = min_dis;
				others.erase(others.begin() + ii);
				ii = ii - 1;
			}
		}
		
	}

	
	return dis;
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
	int planets;
	vector<int> rows, cols;

	int temp_row, temp_col;
	int *output;
	for (int i = 0; i < T; i++)
	{
		if (i == 44)
		{
			cout << "ccccc" << endl;
		}
		rows.clear();
		cols.clear();
		data_file >> planets;
		for (int j = 0; j < planets; j++)
		{
			data_file >> temp_row >> temp_col;
			rows.push_back((temp_row - 1));
			cols.push_back((temp_col - 1));
		}
		output = find_shortest_path(planets, rows, cols);
		result_file << "case #" << (i+1) << ": ";
		cout << "case #" << (i+1) << ": ";
		for (int j = 0; j < planets; j++)
		{
			result_file << output[j] << " ";
			cout << output[j] << " ";
		}
		result_file << endl;
		cout << endl;
	}


	system("pause");
	return 0;
}

