#include <iostream>

using namespace std;

int requestedFires[100000][4] = { 0, }; //requestedFires[i][0] = ��ġ �ð�, requestedFires[i][1] = ��ġ x ��ǥ, requestedFires[i][2] = ��ġ y ��ǥ
// requestedFires[i][3] = ��ġ ����
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> requestedFires[i][0] >> requestedFires[i][1] >> requestedFires[i][2];
		
	cout << endl;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < i; j++) {

			if (requestedFires[j][3]) {
				if (requestedFires[i][0] - requestedFires[j][0] >= 300) {
					requestedFires[j][3] = 0;
					continue;
				}
				else {
					if (sqrt(pow(requestedFires[i][1] - requestedFires[j][1], 2) + pow(requestedFires[i][2] - requestedFires[j][2], 2)) < 5) {
						cout << "E_FAILED" << endl;
						goto EXIT;
					}
				}
			}
		}
		requestedFires[i][3] = 1;
		cout << "S_OK" << endl;
	EXIT:;

	}
}