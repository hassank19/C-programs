//employee information using array of structs
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct employee{
  int age;
  float salary;
  char name[50];
  //bool isRemote;
};

//display
void display(struct employee em){
    printf("\n Name: %s", em.name);
    printf("\n Age: %d", em.age);
    printf("\n Salary: %.2f", em.salary);
    printf("\n");
}

int main(){
    int avg, n, i, choice;
    struct employee emp_of_month = {26, 5450.5, "Alex"}; //example for static 
    printf("Enter the number of employes: ");
    scanf("%d", &n);
    
    struct employee emp[n]; //array of structs
    
    for(i = 0; i < n; i++){
        printf("Enter the age of employee %d: ", i+1);
        scanf("%d", &emp[i].age);
        printf("Enter the salary of employee %d: ", i+1);
        scanf("%f", &emp[i].salary);
        printf("Enter the name of employee %d: ", i+1);
        scanf("%s", &emp[i].name);
    }
    
    printf("Do you choose to display employee information?\n1: Yes \n2: No\n");
    scanf("%d", &choice);
    
    if (choice == 1){
        for (i = 0; i < n; i++){
            display(emp[i]);
        }
    }
    else{
        printf("Program ends");
    }

    return 0;
}