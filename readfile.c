#include <stdio.h>
int main(){
    FILE *ptr = fopen("test.txt", "r");
    char buffer[1024] = {0};
    if (ptr == NULL){
        printf("Couldnt open file");
    }

    while(fgets(buffer, sizeof(buffer), ptr) != NULL){
        printf("%s", buffer);
    }


    fclose(ptr);
    return 0;
}