// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>

#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/

int readValidID(void) {
    int i;
    printf("Enter student ID: ");
    i = readInt();
    while ( i <1000000 || i  >= 10000000 || i == -1){
        printf("Not valid. Enter a valid value: ");
        i = readInt();
    }

   return i;  /* needs to be replaced */
}

int readValidCredits(void) {
    int j;
    printf("Enter credit points: ");
    j = readInt();
//    if ( j <2 || j  > 480 || j == -1){
//        printf("Not valid. Enter a valid value: ");
    while ( j <2 || j  > 480 || j == -1){
        printf("Not valid. Enter a valid value: ");
        j = readInt();
    

        }

   return j;  /* needs to be replaced */
}

float readValidWAM(void) {
    float k;
    printf("Enter WAM: ");
    k = readFloat();
//    if ( k <50 || k  > 100 || k ==-1){
//        printf("Not valid. Enter a valid value: ");
    while ( k <50 || k  > 100 || k ==-1){
        printf("Not valid. Enter a valid value: ");
        k = readFloat();
    }
   return k;  /* needs to be replaced */
}

void printStudentData(int zID, int credits, float WAM) {
    printf("------------------------\n");
    printf("Student zID: z%d\n", zID);
    printf("Credits: %d\n", credits);
    if (85 <= WAM && WAM<= 100){
        printf("Level of performance: HD\n");
    }
    
    if (75 <= WAM && WAM < 85){
        printf("Level of performance: DN\n");
    }

    if (65 <= WAM && WAM < 75){
        printf("Level of performance: CR\n");
    }
    if (50 <= WAM && WAM <65){
        printf("Level of performance: PS\n");
    }

    printf("------------------------\n");

   return;  /* needs to be replaced */
}
