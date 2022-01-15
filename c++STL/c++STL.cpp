#include <iostream>
#include "vector.h"

using namespace std;
int main(void) {
	CVector<int> a;
	CVector<int> b(30);
	a.push_back(1); a.push_back(2); a.push_back(3);
	b.push_back(3); b.push_back(2); b.push_back(1); b.push_back(0);

	cout << (a > b) << endl;
}