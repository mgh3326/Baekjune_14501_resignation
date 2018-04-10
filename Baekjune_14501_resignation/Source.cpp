#include<iostream>
#include<vector>
using namespace std;
unsigned nChoosek(unsigned n, unsigned k)//콤비네션 함수
{
	if (k > n) return 0;
	if (k * 2 > n) k = n - k;
	if (k == 0) return 1;

	int result = n;
	for (int i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}
int count_num(const vector<int>& v, const int num)
{
	int res = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
			res++;
	}
	return res;
}
int jumpCase(int n)
{
	int answer = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back(1);
	}
	for (int i : v)
	{
		cout << "(" << i << ")";
	}
	cout << endl;
	//answer++;
	cout << count_num(v, 1) << endl;
	int index = 0;
	while (true)
	{

		cout << (answer += nChoosek(v.size(), count_num(v, 1))) << endl;
		if (v.back() == 2)
			break;
		else if (v.back() == 1)
		{
			v.pop_back();
			if (index == v.size())
				break;
			v[index++]++;
		}

	}
	return answer;
}
int resignation(int n) {
	int answer = 0;
	int input = 0;
	vector<vector<int> > v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		v[i].resize(2);
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v[i][0] = input;

		cin >> input;
		v[i][1] = input;


	}
	for (int i = 0; i < n; i++) {//출력

		cout << v[i][0] << "	";
		cout << v[i][1] << endl;
	}
	//cout <<"	"<< v.size();

	for (int i = 0; i < n; i++)
	{

		int temp = 0;
		int index = i;
		/*if (index >= n)
			continue;*/
		temp += v[i][1];
		index += v[i][0];
		if (index >= n)
			continue;


		while (index + v[index][0] < n)
		{
			temp += v[index][1];
			index += v[index][0];
		}
		
		/*for (int j = index; j < n; j++) {
			temp += v[index][1];
			index += v[index][0];
		}*/
		if (v[n - 1][0] == 1)
		{
			temp += v[n - 1][1];
		}
		cout << "temp : " << temp << "	index : " << index << endl;
		if (answer < temp)
			
			answer = temp;

	}
	cout << endl;
	return answer;
}
int main()
{

	int test = 0;
	cin >> test;
	//아래는 테스트로 출력해 보기 위한 코드입니다.
	cout << resignation(test) << endl;
}
