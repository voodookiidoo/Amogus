#include <iostream>
#include "vector"

using namespace std;
typedef vector<int> vint;

int main() {
	vint nums = {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0};
	int max_dist = 0;
	int max_ind = 0;
	cout << '1';
	int left, right, zero;
	for (zero = 0; zero < nums.size(); zero++) {
		if (nums[zero] != 0) continue;
		for (left = zero, right = zero;;) {
			if (nums[left] != 1 & left >= 0) left--;
			if (nums[right] != 1 & right <= nums.size()) right++;
			if ((nums[left] == 1 || left < 0) && (nums[right] == 1 || right > nums.size())) break;
		}
		if (left >= 0 && right <= nums.size()) {
			if (min(right - zero, zero - left) > max_dist) {

				max_ind = zero;
				max_dist = (min(right - zero, zero - left));
			}
		} else {
			if (left < 0 && right - zero > max_dist) {
				max_ind = zero;
				max_dist = right - zero;
			} else if (right > nums.size() && zero - left > max_dist) {
				max_ind = zero;
				max_dist = zero - left;
			}
		}
	}
	cout << max_ind;
}
