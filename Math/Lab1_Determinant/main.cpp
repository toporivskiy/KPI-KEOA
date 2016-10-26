//
// Powered by Andrew Toporivskiy
// 10.09.2016
//
// Project for calculate determinant of matrix [nxn]
//


#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

void main()
{
	/*
	A << 1, 2, 1,
		2, 1, 0,
		-1, 1, 2;
		*/
	cout << "Enter the dimension of the matrix A:\n";
	int n;
	cin >> n;
	MatrixXf A(n, n);
	cout << "Enter the elements of the matrix A:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j<n; j++)
		{
			cin >> A(i, j);
		}
	}
	cout << "Here is the matrix A:\n" << A << endl;
	cout << "The determinant of A is (|A|): " << A.determinant() << endl;
	system("pause");
}
