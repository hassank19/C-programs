//digital clock in c
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
int main(){
    time_t my_time = 0;
    bool isRunning = true;
    struct tm *ptr = NULL;
    //printf("Digital clock in C");


    while(isRunning){
        time(&my_time); //time() gives time since Jan 1st 1970, and time(&variable) updates the variable my time by the address
        ptr = localtime(&my_time);  //local time converts the seconds passed into readable format of hours, min, sec. local time returns pointer to struct tm, which is why we did ptr = localtime()
        printf("\r%02d:%02d:%02d", ptr->tm_hour, ptr->tm_min, ptr->tm_sec);
        sleep(1);
    }

    return 0;
}