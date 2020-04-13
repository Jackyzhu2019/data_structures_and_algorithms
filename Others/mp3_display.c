#include <stdio.h>
#include <string.h>

#define MAX_STEP 200
void display_song(int *d_s1,
                  int *d_s2,
                  int *d_s3,
                  int *d_s4,
                  int *pointer,
                  int num_of_songs,
                  char cmd){
     int temp;
    if (cmd == 'U'){
       if (*pointer == *d_s4){
           *pointer = *d_s3;
       }else if (*pointer == *d_s3){
           *pointer = *d_s2;
       }else if (*pointer == *d_s2){
           *pointer = *d_s1;
       }else {
           *d_s4 = *d_s3;
           *d_s3 = *d_s2;
           *d_s2 = *d_s1;

           temp = *d_s1 - 1;
           if (temp == 0){
               *d_s1 = num_of_songs;
           }else{
               *d_s1 = temp;
           }

           *pointer = *d_s1;
       }
    }

    if (cmd == 'D'){
       if (*pointer == *d_s1){
           *pointer = *d_s2;
       }else if (*pointer == *d_s2){
           *pointer = *d_s3;
       }else if (*pointer == *d_s3){
           *pointer = *d_s4;
       }else {
           *d_s1 = *d_s2;
           *d_s2 = *d_s3;
           *d_s3 = *d_s4;

           temp = *d_s4 + 1;
           if (temp == (num_of_songs+1)){
               *d_s4 = 1;
           }else{
               *d_s4 = temp;
           }
           *pointer = *d_s4;
       }
    }

}


int mp3_display(){
    int num_of_songs;
    int i, len;
    char command[MAX_STEP]="DDUUUDUUDDUDUUUUDUDDDDDUDUUDDUUDUDDUUUDUUUUUDDDDUDDDUUUDUUUDDDDDUDDDDDUDDDDDUDDUDDDDU";
    int d_s1, d_s2, d_s3, d_s4;
    int pointer;

    //scanf("%d\n", &num_of_songs);
    //gets(command);
    num_of_songs = 81;


    len = strlen(command);
    d_s1 = 1;
    d_s2 = 2;
    d_s3 = 3;
    d_s4 = 4;
    pointer = 1;

    for(i=0;i<len;i++){
        display_song(&d_s1,
                     &d_s2,
                     &d_s3,
                     &d_s4,
                     &pointer,
                     num_of_songs,
                      command[i]);
    }

    printf("%d %d %d %d\n", d_s1, d_s2, d_s3, d_s4);
    printf("%d", pointer);
    return 0;
}
