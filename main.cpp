#include <math.h>
#include <complex>
#include <vector>
#include <iostream>
#include <iomanip>

std::vector<std::complex<double>> dft(std::vector<std::complex<double>> X){
    int N = X.size();
    int K = N;

    std::complex<double> intSum;

    std::vector<std::complex<double>> output;
    output.reserve(K);

    for (int k = 0; k < K; k++)
    {
        intSum = std::complex<double>(0,0);
        for (int n = 0; n < N; n++)
        {
            double realPart = cos(((2*M_PI)/N) * k * n);
            double imagPart = sin(((2*M_PI)/N) * k * n);
            std::complex<double> w (realPart, imagPart);
            intSum += X[n] * w;
        }
        output.push_back(intSum);
    }
    return output;
}