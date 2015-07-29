#include <iostream>
using namespace std;

/**
 * 分析：题目不严谨。
 * 题目成立的条件应该是 a, b 互质，且 a, b 都不能为 1。
 */

int main(void) {
	int a, b;
	cin >> a >> b;
	cout << a * b - a - b << endl;
	return 0;
}
