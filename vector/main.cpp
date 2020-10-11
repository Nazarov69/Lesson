#include <iostream>
#include "MyVector.h"
#include "MyMatrix.h"
using namespace std;

int main()
{
	TVector<int> a(3, 3);
	TMatrix<int> q(5), k(5), v(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			q[i][j] = i * 10 + j;
			k[i][j] = (i * 10 + j) * 100;
		}
	}
	v = q + k;
	cout << a << "\nHi\n";
	cout << "TMatrix:" << endl << v;

  return 0;
}
