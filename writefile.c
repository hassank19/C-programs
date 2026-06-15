//write to a file
#include <stdio.h>
int main(){
    char arr[50];
    FILE *fptr = fopen("test.txt", "w");

    if (fptr == NULL){
        printf("Couldnt open file");
        return 1;
    }
    
    printf("Enter your text: ");
    scanf("%s", &arr);

    fprintf(fptr, "%s", arr); 
    printf("File was written succesfully");

    fclose(fptr);
}