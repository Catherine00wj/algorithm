/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Student record manager

     COMP9024 17s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "studentRecord.h"
#include "studentLL.h"

void printHelp();
void StudentLinkedListProcessing();

int main(int argc, char *argv[]) {
   if (argc == 2) {
       int count;
       int i;
       int zID;
       int credits;
       float WAM;
       int credits_count = 0;
       float WAM_count = 0.0;
       float average_W = 0.0;
       float Wei_average_W = 0.0;
       count = atoi(argv[1]);
       float WAM_WEI = 0.0;
//       int  arry;
//       int *arr;
       
       
       studentRecordT *record1;
       record1= (studentRecordT*)calloc(count,sizeof(studentRecordT));
       for (i = 0; i< count ; i++){
           zID = readValidID();
           credits =readValidCredits();
           WAM = readValidWAM();
           record1[i].zID = zID;
           record1[i].credits = credits;
           credits_count += record1[i].credits;
           record1[i].WAM = WAM;
           WAM_count += record1[i].WAM;
           WAM_WEI +=record1[i].WAM *record1[i].credits;
       }
        for (i = 0; i < count ; i++){
               printStudentData( record1[i].zID, record1[i].credits,  record1[i].WAM);
               
       }
       average_W = WAM_count/count;
       Wei_average_W = WAM_WEI/credits_count;
       printf("Average WAM: %.3f\n",average_W);
       printf("Weighted average WAM: %.3f\n",Wei_average_W);


      /*** Insert your code for stage 1 here ***/
      
   } else {
      StudentLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void StudentLinkedListProcessing() {
    int op, ch;
    int n=0;
    float wam=0;
    float w_wam=0;
    int zID;
    int credits;
    float WAM=0;

   List list = newLL();   // create a new linked list
   
   while (1) {
      printf("Enter command (a,f,g,p,q, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }
       
      switch (op) {

         case 'a':
         case 'A':
              zID = readValidID();
              credits =readValidCredits();
              WAM = readValidWAM();
              insertLL(list,zID,credits,WAM);
              
            
              /*** Insert your code for adding a student record ***/

	    break;

         case 'f':
         case 'F':
              zID = readValidID();
              inLL(list, zID);

            /*** Insert your code for finding a student record ***/

	    break;
	    
         case 'g':
         case 'G':
              getStatLL(list, &n, &wam, &w_wam);

            /*** Insert your code for getting statistical information ***/

	    break;
	    
         case 'h':
         case 'H':
            printHelp();
	    break;
	    
         case 'p':
         case 'P':
              showLL(list);

            /*** Insert your code for printing all student records ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" A - Add student record\n" );
   printf(" F - Find student record\n" );
   printf(" G - Get statistics\n" );
   printf(" H - Help\n");
   printf(" P - Print all records\n" );
   printf(" Q - Quit\n");
   printf("\n");
}
