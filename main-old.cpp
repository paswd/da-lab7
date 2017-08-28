#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const size_t MAX_SIZE = 501;

typedef long long TNumber;


int main(void) {
	size_t height;
	size_t width;
	cin >> height >> width;
	char map[MAX_SIZE][MAX_SIZE];

	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}
	 
	TNumber result = 0;
	vector<TNumber> dynamics(width, -1);
	vector <TNumber> dynamics_extra[2];
	dynamics_extra[0].resize(width);
	dynamics_extra[1].resize(width);
	stack <TNumber> u_stack;

	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				dynamics[j] = i;
			}
		}

		while (!u_stack.empty()) {
			u_stack.pop();
		}

		for (size_t j = 0; j < width; ++j) {
			while (!u_stack.empty() && dynamics[u_stack.top()] <= dynamics[j]) {
				u_stack.pop();
			}

			if (!u_stack.empty()) {
				dynamics_extra[0][j] = u_stack.top();
			} else {
				dynamics_extra[0][j] = -1;
			}
			u_stack.push(j);
		}

		while (!u_stack.empty()) {
			u_stack.pop();
		}

		for (size_t j_tmp = width; j_tmp > 0; j_tmp--) {
			size_t j = j_tmp - 1;
			while (!u_stack.empty() && dynamics[u_stack.top()] <= dynamics[j]) {
				u_stack.pop();
			}

			if (!u_stack.empty()) {
				dynamics_extra[1][j] = u_stack.top();
			} else {
				dynamics_extra[1][j] = width;
			}
			u_stack.push(j);
		}

		for (size_t j = 0; j < width; j++) {
			result = max(result, (TNumber) (i - dynamics[j]) * (dynamics_extra[1][j] - dynamics_extra[0][j] - 1));
		}
	}
	 
	cout << result << endl;

	return 0;	
}
