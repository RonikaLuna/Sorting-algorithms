#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> BubbleSort(vector<int> nums);

int main() {
	string line;
	vector<int> nums;
	getline(cin, line);
	stringstream ss(line);
	int x;
	while (ss >> x) {
		nums.push_back(x);
	}
	vector<int> sortedNums = BubbleSort(nums);
	for (int i = 0; i < sortedNums.size(); i++) {
		cout << sortedNums[i] << " ";
	}
	cout << endl;
}

vector<int> BubbleSort(vector<int> nums) {
	for (int i = 0; i + 1 < nums.size(); i++) {
		for (int j = 0; j + 1 < nums.size() - i; j++) {
			if (nums[j] > nums[j + 1]) {
				int r = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = r;
			}
		}
	}
	return nums;
}