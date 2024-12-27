#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]) {
    double sum = 0;
    double sumpower = 0;
    double mult = 1;
    double oneoverx = 0;
    double max = A[0], min = A[0];
    for(int i = 0; i < N; i++){
        sum += A[i];
        sumpower += pow(A[i],2);
        mult *= A[i];
        oneoverx += 1/A[i];
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }
    B[0] = sum/N;
    B[1] = sqrt(sumpower/N - pow(B[0],2) );
    B[2] = pow(mult,1.0/N);
    B[3] = N/oneoverx;
    B[4] = max;
    B[5] = min;
}