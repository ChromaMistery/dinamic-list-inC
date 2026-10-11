


#ifndef DVEC_H
#define DVEC_H




#include <stdio.h>
#include <stdlib.h>


typedef struct{

     int size; // cantidad de elementos guardados de verdad
     int capacity; // capacidad maxima en ese momento
     float *data;
 }DVec;

void free_vec(DVec *v){
    free(v->data);

    //temproal

}

DVec vecf_new(){
    DVec v;


    v.size = 0;
    v.capacity = 5;

    v.data = malloc(v.capacity * sizeof(float));


    if (v.data == NULL){
        fprintf(stderr, "ERROR, no se pudo asignar el Vector {Null pointer error} in %s, on line %d calling: vecf_new\n",
            __FILE_NAME__, __LINE__);

        exit(1);
    }


    return v;


}

DVec vecf_new_Dvec_whit_capacity(int capacity){
    DVec v;


    v.size = 0;
    v.capacity = capacity + 1;

    v.data = malloc(v.capacity * sizeof(float));


    if (v.data == NULL){
        fprintf(stderr, "ERROR, no se pudo asignar el Vector {Null pointer error} in %s, on line %d calling: vecf_new_Dvec_whit_capacity\n",
            __FILE_NAME__, __LINE__);

        exit(1);
    }


    return v;
}

/*
 *A veces el problema más chiquito,
 lo convertimos en el más grande y
 cuando nos damos cueta de eso hasta el más grande parece chiquito*

 -Schenaide
 */

void vecf_resize(DVec *v){
    float *tmp;



    if (v->capacity <= v->size){
        v->capacity = v->capacity * 2 + 1;




    tmp = realloc(v->data, v->capacity * sizeof(float));

    if (tmp == NULL){
        fprintf(stderr, "ERROR, no se pudo asignar redimensionar el Vector {Null pointer error} in %s, on line %d calling: vecf_resize\n",
            __FILE_NAME__, __LINE__);

        exit(1);

        free_vec(v);
    }



    v->data = tmp;
    }



}

void vecf_addend(DVec *v, float value){
    vecf_resize(v);
       v->data[v->size] = value;
       v->size += 1;


}

void vecf_removeend(DVec *v){
    if (v->size == 0){
        fprintf(stderr, "ERROR, indice negativo {Negative Index} in %s, on line %d \n calling: vecf_removeend",
            __FILE_NAME__, __LINE__);

        exit(1);
    }

    v->size -= 1;

    v->data[v->size] = sizeof(float);
}

void vecf_removedbyindex(DVec *v, int index){
    if (index >= v->size){
        fprintf(stderr, "ERROR, indice fuera de rango {Out Of Range} in %s, on line %d \n calling: vecf_removedbyindex",
            __FILE_NAME__, __LINE__);

        exit(1);
    }



    if (index < 0){
        fprintf(stderr, "ERROR, indice fuera de rango {Negative index} in %s, on line %d \n calling: vecf_removedbyindex",
            __FILE_NAME__, __LINE__);

        exit(1);
    }




    v->data[index] = sizeof(float);

    for (int i = 0; i < v->size; i++){
        if (i > index){
            v->data[i - 1] = v->data[i];

        }


    }

    v->size -= 1;



}

void vecf_addbyindex(DVec *v, int index, float value){


    if (index > v->size){
        fprintf(stderr, "ERROR, indice fuera de rango {Out Of Range} in %s, on line %d \n calling: vecf_addbyindex",
            __FILE_NAME__, __LINE__);

        exit(1);
    }


    if (index < 0){
        fprintf(stderr, "ERROR, indice fuera de rango {Negative Index} in %s, on line %d \n calling: vecf_addbyindex",
            __FILE_NAME__, __LINE__);

        exit(1);
    }



    vecf_resize(v);

    for (int i = v->size; i > index; i--){
        v->data[i] = v->data[i - 1];
    }

    v->data[index] = value;
    v->size += 1;





}

float vecf_clonevalue_by_index(DVec v, int index){
    if (index >= v.size){
        fprintf(stderr, "ERROR, indice fuera de rango {Out Of Range} in %s, on line %d \n calling: vecf_clonevalue_by_index",
            __FILE_NAME__, __LINE__);

        exit(1);
    }


    if (index < 0){
        fprintf(stderr, "ERROR, indice fuera de rango {Negative Index} in %s, on line %d \n calling: vecf_clonevalue_by_index",
            __FILE_NAME__, __LINE__);

        exit(1);
    }

    float value = v.data[index];

    return value;

}

DVec vecf_clonevalue_all(DVec v){
    DVec new_v = vecf_new_Dvec_whit_capacity(v.capacity);
    new_v.size = v.size;


    for (int i = 0; i < v.size; i++){
        new_v.data[i] = v.data[i];
    }

    return new_v;
}

void vecf_delete_values(DVec *v){
    for (int i = 0; i < v->size; i++){
        v->data[i] = sizeof(float);

    }

    v->size = 0;
}


#endif
