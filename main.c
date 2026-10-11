#include "fvec.h"
#include <stdio.h>


int main(){
    DVec v = vecf_new();
    vecf_addend(&v, 1.0);
    vecf_addend(&v, 2.0);

    for (int i = 0; i < v.size; i++){
        printf("hola %g \n", v.data[i]);
    }

    free_vec(&v);
    return 0;
}
