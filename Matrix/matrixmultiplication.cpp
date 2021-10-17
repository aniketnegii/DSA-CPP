#include <iostream>
using namespace std;

void mulMat(int mat1[][C1], int mat2[][C2]) {
	int rslt[R1][C2];

	cout << "Multiplication of given two matrices is:\n" << endl;

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			rslt[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				rslt[i][j] += mat1[i][k] * mat2[k][j];
			}

			cout << rslt[i][j] << "\t";
		}

		cout << endl;
	}
}

int main(void) {
    int R1;
    int R2;
    int C1;
    int C2;
    cout<<"Enter the size of first matrix RxC"<<endl;
    cin>>R1>>C1;
    int mat1[R1][C1];
	for(int i=0;i<R1;i++)
    {
        for(int j=0;j<C1;;j++)
            cin>>mat1[i][j]
    }

    cout<<"Enter the size of secondd matrix RxC"<<endl;
    cin>>R2>>C2;
    int mat1[R2][C2];
	for(int i=0;i<R2;i++)
    {
        for(int j=0;j<C2;;j++)
            cin>>mat2[i][j]
    }

	if (C1 != R2) {
		cout << "The number of columns in Matrix-1 must be equal to the number of rows in "
				"Matrix-2" << endl;
		cout << "Please update MACROs according to your array dimension in #define section"
				<< endl;

		exit(EXIT_FAILURE);
	}

	mulMat(mat1, mat2);

	return 0;
}