#include <stdio.h>


union uData {
    int a;
    int b;
};

struct sData {
    union uData c;
    int d;
};

enum Covid_prevention{
    Sanitizer = 1,
    wear = 2,
    soc = 4
};

int main(){
    // int array[] = {10, 20, 30, 40, 50};
    // int *ip array+4, i;
    // for(ip = array + 4, i = 0;i<5;i++){
    //     printf("%d ", ip[-i]);
    // }"%d", myCov);

    int x = 1;
    switch(x){
        case x:
            printf("1");
            break;
        case x+1:
            printf("2q");
            break;
        default:
            printf("de");
    }
    return 0;
}
