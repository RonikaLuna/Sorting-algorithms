#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> BubbleSort(vector<int> nums) {
	int loops = 0;
	for (size_t i = 0; i + 1 < nums.size(); i++) {
		for (int j = 0; j + 1 < nums.size() - i; j++) {
			if (nums[j] > nums[j + 1]) {
				int r = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = r;
			}
			loops++;
		}
	}
	cout << "\nSorted by BubbleSort in " << loops << " steps" << endl;
	return nums;
}
vector<int> ShakerSort(vector<int> nums) {
	int loops = 0;
	size_t left = 0, right = nums.size() - 1;
	while (left <= right) {
		for (size_t i = left; i < right; i++) {
			if (nums[i] > nums[i + 1]) {
				swap(nums[i], nums[i + 1]);
			}
			loops++;
		}
		right--;
		for (size_t i = right; i > left; i--) {
			if (nums[i] < nums[i - 1]) {
				swap(nums[i], nums[i - 1]);
			}
			loops++;
		}
		left++;
	}
	cout << "\nSorted by ShakerSort in " << loops << " steps" << endl;
	return nums;
}
vector<int> CombSort(vector<int> nums) {
	int loops = 0;
	const double factor = 1.247; 
	double step = nums.size() - 1;
	while (step >= 1) {
		for (size_t i = 0; i + step < nums.size(); i++) {
			if (nums[i] > nums[i + step]) {
				swap(nums[i], nums[i + step]);
			}
			loops++;
		}
		step /= factor;
	}
	cout << "\nSorted by CombSort in " << loops << " steps" << endl;
	return nums;
}
vector<int> InsertionSort(vector<int> nums) {
	int loops = 0;
	for (size_t i = 1; i < nums.size(); i++) {
		int x = nums[i];
		size_t j = i;
		while (j > 0 && nums[j - 1] > x) {
			nums[j] = nums[j - 1];
			j--;
			loops++;
		}
		nums[j] = x;
	}
	cout << "\nSorted by InsertionSort in " << loops << " steps" << endl;
	return nums;
}
vector<int> SelectionSort(vector<int> nums) {
	int loops = 0;
	for (size_t i = 0; i + 1 < nums.size(); i++) {
		size_t min = i;
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[min] > nums[j]) {
				min = j;
			}
			loops++;
		}
		swap(nums[i], nums[min]);
	}
	cout << "\nSorted by SelectionSort in " << loops << " steps" << endl;
	return nums;
}
int Partition(vector<int>& nums, int l, int r, int& loops) {
	int x = nums[r];
	int less = l;
	for (int i = l; i < r; i++) {
		if (nums[i] <= x) {
			swap(nums[i], nums[less]);
			less++;
		}
		loops++;
	}
	swap(nums[less], nums[r]);
	return less;
}
void QuickSortImpl(vector<int>& nums, int l, int r, int& loops) {
	if (l < r) {
		int q = Partition(nums, l, r, loops);
		QuickSortImpl(nums, l, q - 1, loops);
		QuickSortImpl(nums, q + 1, r, loops);
	}
}
vector<int> QuickSort(vector<int> nums) {
	int loops = 0;
	QuickSortImpl(nums, 0, nums.size() - 1, loops);
	cout << "\nSorted by QuickSort in " << loops << " steps" << endl;
	return nums;
}