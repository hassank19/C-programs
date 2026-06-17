#include <stdio.h>
#include <string.h>

int view_con(){
    FILE *ptr = fopen("contact.txt", "r");
    if (ptr == NULL){
        printf("\n Couldnt open file");
        return 1;
    }

    char buffer[1024] = {0};


    printf("Displaying contacts: ");
    while (fgets(buffer, sizeof(buffer), ptr) != NULL){
        printf("\n%s", buffer);
    }
    fclose(ptr);
    return 0;
}


int add_con(){
    char arr[100];
    FILE *ptr = fopen("contact.txt", "a");
    if (ptr == NULL){
        printf("\n Couldnt open file");
        return 1;
    }
    printf("\nEnter the contact number : ");
    scanf("%s", &arr);

    fprintf(ptr, "%s\n", arr);
    printf("Contact added!");
    fclose(ptr);
    return 0;

}

int search_con(){
    FILE *ptr = fopen("contact.txt", "r");
    char arr[100] = {0};
    if (ptr == NULL){
        printf("\n Couldnt open file");
        return 1;
    }

    printf("\nEnter the contact you want to search: ");
    scanf("%s", arr);
    char buffer[1024] = {0};

    while (fgets(buffer, sizeof(buffer), ptr) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, arr) == 0){ //if the current string in buffer compares to what the user input is, strcmp returns 0
            printf("\nContact found: %s\n", arr);
            return 1;
        }
    }
    printf("Contact not found");
    fclose(ptr);
    return 0;
}

int del_con(){
    int found = 0;
    FILE *ptr = fopen("contact.txt", "r"); /* Open the original file for reading. Open a temporary file for writing. Copy every contact except the one to delete. Close both files. Delete the original file.
Rename the temporary file to the original filename.*/
    FILE *temp = fopen("temp.txt", "w");

    if (ptr == NULL || temp == NULL){
        printf("\nCouldnt open file");
        return 1;
    }

    char buffer[1024] = {0};
    char arr[100] = {0};
    printf("Enter the contact you want to delete: ");
    scanf("%s", arr);

    while (fgets(buffer, sizeof(buffer), ptr) != NULL) //read all lines
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, arr) == 0){
            found = 1; //bool for the later if else conditons
            continue; //if the current thing in buffer is the contact we wanna delete, then skip it (by using continue), then write in the new file
        }
        fprintf(temp, "%s\n", buffer); //will write all the lines in file, except the target, due to the continue
    }
    fclose(ptr);
    fclose(temp);

    remove("contact.txt"); //delete original
    rename("temp.txt", "contact.txt"); //rename temp as original

    if (found){
        printf("\nContact deleted");
    }
    else{
        printf("Contact not found");
    }
    
    return 0;   
}

int main(){
    int choice;
    while (1){
        printf("\n1: View contacts \n2: Add contact \n3: Search Contacts \n4: Delete contact");
        printf("\nChoose your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            view_con();
            break;
        case 2:
            add_con();
            break;
        case 3:
            search_con();
            break;
        case 4:
            del_con();
            break;
        default:
            printf("Invalid Input");
            break;
        }

    }
    return 0;
}