#include <stdio.h>
#include <stdlib.h>

int* const count(int *const array, size_t len, size_t max){
    int i=0, j=0;
    int* const new_array = (int*)calloc(max, sizeof(int));
    if (new_array==NULL){
        free(new_array);
        return new_array;
    }
    for (i=0; i<len; i++){
        int index = i;
        for (j=0; j<max; j++){
            if (array[i] > new_array[j]) {
                index = j;
                break;
            }
        }
        if (index<max) {
            for (j = max - 1; j > index; j--) {
                new_array[j] = new_array[j - 1];
            }
            new_array[index] = array[i];
        }
    }
    for (i = 0; i < max; i++) printf("%d ", new_array[i]);
    return new_array;
}

void error(){
    printf("[error]");
}

int main() {
    int len=0, max=0, i=0, err=0;
    err=scanf("%d", &len);
    if (err==0 || len<=0) error();
    else{
        size_t n=(size_t)len;
        int* const array = (int *) calloc(n, sizeof(int));
        if (array==NULL){
            free(array);
            return 0;
        }
        err=0;
        for (i = 0; i < n; i++) {
            err+=scanf("%d", array + i);
        }
        if (err!=n) error();
        else {
            err=scanf("%d", &max);
            if (err==0 || max<0 || max>n) error();
            else{
                size_t m = (size_t)max;
                free(count(array, n, m));
            }
        }
        free(array);
    }
    return 0;
}