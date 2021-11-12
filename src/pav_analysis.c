#include  <stdio.h>
#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N)
{
    float power = 0;
    for (int i = 0; i <= N - 1; i++)
    {
        power = power + x[i] * x[i];
    }
    return 10 * log10((1.0 / N) * power);
}

float compute_am(const float *x, unsigned int N)
{
    float am = 0.0;
    for (int i = 0; i <= N - 1; i++)
    {
        am = am + fabs(x[i]);
    }
    return am / N;
}

float compute_zcr(const float *x, unsigned int N, float fm)
{
    float zcr = 0.0;
    for (int i = 1; i < N; i++)
    {
        if ((x[i] >= 0 && x[i - 1] < 0) || (x[i] < 0 && x[i - 1] >= 0))
        {
            zcr = zcr + 1.0;
        }
    }
    return (fm / 2.0) * (1.0 / (N - 1)) * zcr;
}

float finestra_hamming(int n, int N)
{
    return(0.54 - 0.46*cos(2*n*N*M_PI));
}

float compute_power_hamming(const float *x, unsigned int N, float fm)
{
    float num = 0.0;
    float den = 0.0;

    for(int i = 0; i < N; i++){
        num = num + pow(x[i]*finestra_hamming(i, N), 2);
        den = den + pow(finestra_hamming(i, N), 2);
    }

    return 10*log10(num/den);
}