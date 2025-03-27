#include <iostream>
using namespace std;

/*
This multiplies a vector of length N with an N×3 matrix and returns a new vector of size 3.

Q: How does the flat initializer list map onto the 2D array?
→ The list fills the array in row-major order:
   double mtx[2][3] = {1, 2, 3, 4, 5, 6} maps like:
   mtx[0][0]=1, [0][1]=2, [0][2]=3
   mtx[1][0]=4, [1][1]=5, [1][2]=6
*/

double* multiply(double vec[], int N, double mtx[][3]) {
    double* out = new double[3];
    for (int i = 0; i < 3; ++i) out[i] = 0.0;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            out[j] += vec[i] * mtx[i][j];

    return out;
}

int main() {
    double v[2] = {1, 2};
    double mtx[2][3] = {
        {1, 0, 2},
        {0, 3, 4}
    };

    double* res = multiply(v, 2, mtx);
    cout << "Result of vector × matrix: ";
    for (int i = 0; i < 3; ++i)
        cout << res[i] << " ";
    cout << endl;

    delete[] res;
    return 0;
}
