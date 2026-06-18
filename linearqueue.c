#include <stdio.h>
int size, x, i, value, front = -1, rear = -1;

int main(){
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    int Q[size];
    
    while(1){
    
    printf("Choose an operation: ");
    printf("1: EnQueue\n");
    printf("2: DeQueue\n");
    printf("3: Display\n");
    printf("4: Exit\n");
    scanf("%d", &x);
    
    if (x == 1){
        printf("Enter the value you want to insert: ");
        scanf("%d", &value);
        if (rear == size - 1){
            printf("Queue is full, cannot insert");
        }
        else{
            if (front == -1){
                front = 0;
            }
            rear++;
            Q[rear] = value;
        }
    }
    
    if (x == 2){
        if (front == -1 || rear == -1){
            printf("Queue is empty, cannot delete an element");
        }
        else {
            printf("Element deleted %d\n", Q[front]);
            front++;
            if (front > rear){
                front = rear = -1;
            }
        }
    }
    
    if (x == 3){
        printf("Displaying Queue elements: ");
        for(i = front; i <= rear; i++){
            printf("%d\n", Q[i]);
        }
    }
    
    if (x == 4){
        break;
    }
    
    }
    return 0;
}