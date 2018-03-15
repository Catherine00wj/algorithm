#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "studentLL.h"
#include "studentRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    studentRecordT data;
    struct node    *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;
/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/


// Time complexity: O(1)
// Explanation: Becuse there is no "for" or "while" circulation and just take new place ofr the list.
List newLL() {
    List NewLL = malloc(sizeof(List));
    NewLL->head = (NodeT *)malloc(sizeof(NodeT));
    NewLL->head->data.zID = 0;
    NewLL->head->data.credits = 0;
    NewLL->head->data.WAM = 0.0;
    NewLL->head->next = NULL;
    
return NewLL;  /* needs to be replaced */
}
// Time complexity: O(n)
// Explanation:because there is a "while" circulation.
void dropLL(List listp) {
    NodeT *p ;
    p = listp->head;
    while(p !=NULL ){
        NodeT  *temp = p->next;
        free(p);
        p = temp;
    }
   return;  /* needs to be replaced */
}

// Time complexity:O(n)
// Explanation: Because there is a 'while' circulation.
void inLL(List listp, int zid) {
    if ( zid <1000000 || zid  >= 10000000 ){
        printf("Not valid. Enter a valid value: ");
        scanf("%d",&zid);
    }
    NodeT *p;
    p = listp->head->next;
    int f =0;
    while(p!= NULL){
        if (p->data.zID == zid){
            f =1;
            printf("------------------------\n");
            printf("Student zID: z%d\n", p->data.zID);
            printf("Credits: %d\n", p->data.credits);
            if (85 <= p->data.WAM && p->data.WAM<= 100){
                printf("Level of performance: HD\n");
            }
            
            if (75 <= p->data.WAM && p->data.WAM <85){
                printf("Level of performance: DN\n");
            }
            
            if (65 <= p->data.WAM && p->data.WAM <75){
                printf("Level of performance: CR\n");
            }
            if (50 <= p->data.WAM && p->data.WAM <65){
                printf("Level of performance: PS\n");
            }
            printf("------------------------\n");
        
        }
        p= p->next;
    }
    if (f == 0){
        printf("No record found.\n");
    }
    return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: Because there is a 'while' circulation.
void insertLL(List listp, int zid, int cr, float wam) {
    NodeT *Newnode = (NodeT *)malloc(sizeof(NodeT));
    Newnode->data.zID = zid;
    Newnode->data.credits = cr;
    Newnode->data.WAM = wam;
    NodeT *p;
    NodeT *temp;
    temp = listp->head;
    p = temp->next;
    int f=0;
    while (p!= NULL){
        if (p->data.zID == zid){
            f=1;
            break;
        }
        if (p->data.zID > zid){
            break;
        }
        temp = p;
        p =p->next;
    
    }
    if(f==1){
        p->data.credits = cr;
        p->data.WAM = wam;
        printf("Student record updated.\n");
    }else{
    Newnode->next = p;
    temp->next = Newnode;
        printf("Student record added.\n");}
    return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: Because there is a 'while' circulation.
void getStatLL(List listp, int *n, float *wam, float *w_wam) {
    int count_record =0;
    float count_wam =0.0;
    int count_credits = 0;
    float wam_wei= 0.0;

    NodeT *p;
    p = listp->head->next;
    while (p!= NULL){
        count_record++;
        count_wam += p->data.WAM;
        count_credits += p->data.credits;
        wam_wei=wam_wei+(p->data.WAM) * (p->data.credits);
        p = p->next;
    }
    *n = count_record;
    *wam = count_wam/count_record;
    *w_wam = wam_wei/count_credits;
    printf("Number of records: %d\n", *n);
    printf("Average WAM: %.3f\n", *wam);
    printf("Average weighted WAM: %.3f\n", *w_wam);
    return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: Because there is a 'while' circulation.
void showLL(List listp) {
    NodeT *p;
    
    p = listp->head->next;
    while (p!= NULL){
        printf("------------------------\n");
        printf("Student zID: z%d\n", p->data.zID);
        printf("Credits: %d\n", p->data.credits);
        if (85 <= p->data.WAM && p->data.WAM<= 100){
            printf("Level of performance: HD\n");
        }
        
        if (75 <= p->data.WAM && p->data.WAM < 85){
            printf("Level of performance: DN\n");
        }
        
        if (65 <= p->data.WAM && p->data.WAM < 75){
            printf("Level of performance: CR\n");
        }
        if (50 <= p->data.WAM && p->data.WAM <65){
            printf("Level of performance: PS\n");
        }
        printf("------------------------\n");
        p = p->next;
    }
   return;  /* needs to be replaced */
}
