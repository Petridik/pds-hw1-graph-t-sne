#include "data.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double now(void){
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + 1e-9 * t.tv_nsec;
}

double enrtopy(const double *w, int d, double wmax, double beta, double *p){
    double sum = 0,  H = 0;
    for (int i = 0; i < d; i++){
        p[i] = pow(w[i] / wmax, beta); sum += p[i];
    }
    for (int i = 0; i < d; i++){
        p[i] /= sum;
        if(p[i] > 0){
            H -= p[i] * log(p[i]);
        }
    }
    return H; 
}