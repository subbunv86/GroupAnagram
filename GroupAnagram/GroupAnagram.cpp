// GroupAnagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		map<string, vector<string>> resultMap;
		map<string, vector<string>>::iterator it;
		string sSorted;
		vector<string> resultVector;
		vector< vector<string>> returnVector;
		string s;
		for (int i=0; i<strs.size();i++)
		{
			s = strs[i];
			sort(s.begin(), s.end());
			if ((it = resultMap.find(s)) != resultMap.end())
			{
				resultVector = it->second;
				resultVector.push_back(strs[i]);
				it->second = resultVector;
			}
			else
			{
				resultVector.clear();
				resultVector.push_back(strs[i]);
				resultMap.insert(pair<string, vector<string>>(s, resultVector));
			}
		}
		for (it = resultMap.begin(); it != resultMap.end(); it++)
			returnVector.push_back(it->second);
		return returnVector;
	}
};

int main()
{
	vector<string> inputStr = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> result;
	Solution slnObj;
	result = slnObj.groupAnagrams(inputStr);
		std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
