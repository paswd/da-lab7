#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const size_t MAX_SIZE = 501;

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
				//map[i][j] = 1; //INVERT AFTER TESTING!!!
			} else {
				map[i][j] = 1;
				//map[i][j] = 0; //INVERT AFTER TESTING!!!
			}
		}
	}

	int tmp[MAX_SIZE];
	for (size_t i = 0; i < width; i++) {
		tmp[i] = 0;
	}
	cout << endl;

	size_t res = 0;
	for (size_t i = 0; i < height; i++) {
		size_t res_tmp = 0;
		size_t min_height = 0;
		size_t current_width = 0;
		for (size_t j = 0; j < width; j++) {
			if (map[i][j] != 0) {
				tmp[j]++;
			} else {
				tmp[j] = 0;
			}
			cout << tmp[j] << ' ';

			if (tmp[j] == 0) {
				res_tmp = 0;
				min_height = 0;
				current_width = 0;
				continue;
			}

			current_width++;

			if (min_height == 0 || (size_t) tmp[j] < min_height) {
				//cout << "min_height = " << min_height << endl;
				//cout << "tmp[j] = " << tmp[j] << endl;
				min_height = tmp[j];
			}
			res_tmp = current_width * min_height;
			cout << current_width << " * " << min_height << " = " << res_tmp << endl;
			if (res_tmp > res) {
				res = res_tmp;
			}
		}
		cout << endl;
	}

	cout << res << endl;

	return 0;	
}
