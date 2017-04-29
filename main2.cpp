#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const size_t MAX_SIZE = 501;

class TContainer {
public:
	size_t Horisontal;
	size_t Vertical;
	size_t Square;
	int NearestUnitHorisontal[2];
	int NearestUnitVertical[2];

	TContainer(void) {
		this->Horisontal = 0;
		this->Vertical = 0;
		this->Square = 0;
		this->NearestUnitHorisontal[0] = -1;
		this->NearestUnitHorisontal[1] = -1;
		this->NearestUnitVertical[0] = -1;
		this->NearestUnitVertical[1] = -1;
	}
	~TContainer(void) {
	}
	void SetUnitSize(void) {
		this->Horisontal = 1;
		this->Vertical = 1;
		this->Square = 1;
	}
};

int main(void) {
	char map[MAX_SIZE][MAX_SIZE];
	TContainer data[MAX_SIZE][MAX_SIZE];
	size_t n, m;
	cin >> n >> m;
	size_t res = 0;
	//int tmp;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			/*cin >> tmp;
			map[i][j] = tmp;*/
			//ReadCharAsInt(&(map[i][j]));
			scanf("%d", &(map[i][j]));
			if (map[i][j] == 0) {
				data[i][j].SetUnitSize();
			}
			if (i > 0) {
				if (map[i - 1][j] == 0) {
					data[i][j].Vertical = data[i - 1][j].Vertical + 1;
					if (data[i - 1][j].NearestUnitVertical > 0) {
						data[i][j].NearestUnitVertical = data[i - 1][j].NearestUnitVertical + 1;
					}
				} else {

				}
			}
			if (j > 0) {
				if (map[i][j - 1] == 0) {
					data[i][j - 1].Horisontal = data[i][j - 1].Horisontal + 1;
					if (data[i][j - 1].NearestUnitHorisontal > 0) {
						data[i][j].NearestUnitHorisontal = data[i][j - 1].NearestUnitHorisontal + 1;
					}
				}
			}
		}
	}
	return 0;
}
