#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const size_t MAX_SIZE = 501;

size_t CurrentAreaWidthCalculator(stack <size_t> *st, size_t pos) {
	if (!st->empty()) {
		return pos - st->top() - 1;
	}
	return pos;
}

size_t MaxHistogramArea(int *arr, size_t size) {
	stack <size_t> st;
	size_t area_max = 0;
	size_t stack_top = 0;
	size_t area_current = 0;

	size_t i = 0;
	while (i < size || !st.empty()) {
		if ((st.empty() || arr[st.top()] <= arr[i]) && i < size) {
			st.push(i);
			i++;
		} else {
			stack_top = st.top();
			st.pop();
			area_current = arr[stack_top] * CurrentAreaWidthCalculator(&st, i);

			if (area_current > area_max) {
				area_max = area_current;
			}
		}
	}

	return area_max;
}

int main(void) {
	size_t height;
	size_t width;
	cin >> height >> width;
	char map[MAX_SIZE][MAX_SIZE];

	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			char in_tmp;
			cin >> in_tmp;
			if (in_tmp == '1') {
				map[i][j] = 0;
			} else {
				map[i][j] = 1;
			}
		}
	}

	int tmp[MAX_SIZE];
	for (size_t i = 0; i < width; i++) {
		tmp[i] = 0;
	}

	size_t res = 0;
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			if (map[i][j] != 0) {
				tmp[j]++;
			} else {
				tmp[j] = 0;
			}
		}
		size_t res_tmp = MaxHistogramArea(tmp, width);
		if (res_tmp > res) {
			res = res_tmp;
		}
	}

	cout << res << endl;

	return 0;	
}
