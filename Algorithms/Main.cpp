#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Functions.h"
using namespace std;


int main() {
	string line;
	vector<int> nums;
	getline(cin, line);
	stringstream ss(line);
	int x;
	while (ss >> x) {
		nums.push_back(x);
	}
	vector<int> sortedNums = ShakerSort(nums);
	for (int i = 0; i < sortedNums.size(); i++) {
		cout << sortedNums[i] << " ";
	}
	cout << endl;
}
