#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

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
vector<int> ShakerSort(vector<int> nums) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		for (int i = left; i < right; i++) {
			if (nums[i] > nums[i + 1]) {
				swap(nums[i], nums[i + 1]);
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (nums[i] < nums[i - 1]) {
				swap(nums[i], nums[i - 1]);
			}
		}
		left++;
	}
	return nums;
}
vector<int> CombSort(vector<int> nums) {
	const double factor = 1.247; 
	double step = nums.size() - 1;
	while (step >= 1) {
		for (int i = 0; i + step < nums.size(); i++) {
			if (nums[i] > nums[i + step]) {
				swap(nums[i], nums[i + step]);
			}
		}
		step /= factor;
	}
	return nums;
}