#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define STUDY_PERIOD 25*60 //SECONDS
#define BREAK_PERIOD 7*60 //SECONDS

void alarm(int period){
    time_t start_time = 0;
    time_t curr_time  = 0;
    time(&start_time); 
    time(&curr_time);

    double diff = difftime(curr_time, start_time);

    while(diff < period){
        time(&curr_time);
        diff = difftime(curr_time, start_time);
    }
    printf("%d, seconds (%d minutes) have passed!\n", period, period/60);
}

int main(){
    int study = 1;
    while(1){
        if(study){
            alarm(STUDY_PERIOD);
            study = 0;
        }else{
            alarm(BREAK_PERIOD);
            study = 1;
        }
    }
}