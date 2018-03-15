#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define mixlen 20
#define maxspace 1001
int max_length;
char input_array[maxspace][mixlen];
int  ad_matrix[maxspace][maxspace];
int  chain_position[maxspace][maxspace];
int  d[maxspace];
int  max_chain[maxspace];
char diff_short[mixlen];
int diff_position =0;
int f;

//diff function
int CharDiff(char char1[], char char2[]) {
    int count=0;
    int time =0;
    if(strlen(char1) == strlen(char2)){
        for(int i=0;i<strlen(char1);i++){
            if(char1[i] != char2[i]){
                count++;
            }

        }

    }else{
        if(strlen(char1) < strlen(char2)){
            for(int j=0;j<strlen(char2);j++){
                if(char1[j] != char2[j]){
                    diff_position =j;
                    break ;
                }
            }
            if(strlen(char1) <diff_position+1){
                
                for(f= 0;f<strlen(char1);f++){
                diff_short[f] = char1[f];
            }
                diff_short[diff_position] = char2[diff_position];
            }
            if(strlen(char1)== diff_position+1){
            for(f=0;f<strlen(char1);f++){
                if(f<diff_position){
                    diff_short[f] = char1[f];
                }else{
                    diff_short[f] = char2[f];
                }
                }
                diff_short[diff_position+1] = char1[diff_position];
            }
            if(strlen(char1)> diff_position+1){
            for(f=0;f<strlen(char2);f++){
                if(f<diff_position){
                    diff_short[f] = char1[f];
                }
                if(f==diff_position){
                    diff_short[f] = char2[f];
                }
                if(f>diff_position){
                    diff_short[f] = char1[f-1];
                }
            }
                          }
            for(f=0;f<strlen(diff_short);f++){
                if(diff_short[f] == char2[f]){
                    time++;
                }
            }
            if(time == strlen(char2)){
                count = 1;
            }else{
                count=2;
            }
                       }
        if(strlen(char1) > strlen(char2)){
            for(int j=0;j<strlen(char1);j++){
                if(char1[j] != char2[j]){
                    diff_position =j;
                    break ;
                }
            }
            if(strlen(char2) <diff_position+1){
                
                for(f= 0;f<strlen(char2);f++){
                    diff_short[f] = char1[f];
                }
                diff_short[diff_position] = char1[diff_position];
            }
            if(strlen(char2)== diff_position+1){
                for(f=0;f<strlen(char2);f++){
                    if(f<diff_position){
                        diff_short[f] = char2[f];
                    }else{
                        diff_short[f] = char1[f];
                    }
                }
                diff_short[diff_position+1] = char2[diff_position];
            }
            if(strlen(char2)> diff_position+1){
                for(f=0;f<strlen(char1);f++){
                    if(f<diff_position){
                        diff_short[f] = char2[f];
                    }
                    if(f==diff_position){
                        diff_short[f] = char1[f];
                    }
                    if(f>diff_position){
                        diff_short[f] = char2[f-1];
                    }
                }
            }
            for(f=0;f<strlen(diff_short);f++){
                if(diff_short[f] == char1[f]){
                    time++;
                }
            }
            if(time == strlen(char1)){
                count = 1;
            }else{
                count=2;
            }
        }

    }
    
    return count;
}


//find longest chain function
void Longest(int a,int positon){
    int j;
    if (max_chain[a] == 1) {
        for (j = 1; j <= positon-1; j++) {
            printf("%s -> ", input_array[d[j]]);
        }
        printf("%s\n", input_array[a]);
        return;
    }
    positon = positon + 1;
    for (j = 1; j <= chain_position[a][0]; j++) {
        d[positon] = chain_position[a][j];
        Longest(chain_position[a][j], positon);
    }
    return;
}


//input words
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d",&number);
    for (int i=0;i<number;i++){
        printf("Enter word: ");
        scanf("%s",input_array[i]);
    }
    printf("\n");
        for(int j=0;j<number;j++){
            for(int k= j+1 ;k<number;k++){
                if(CharDiff(input_array[j], input_array[k]) == 1){
                    ad_matrix[j][k] = 1;
                }else{
                    ad_matrix[j][k] = 0;
                    ad_matrix[k][j] = 0;
                }
                
            }
        }
    for(int z=0;z<number;z++){
        printf("%s:",input_array[z]);
        for (int x=0;x<number;x++){
            if (ad_matrix[z][x] ==1){
                printf(" %s",input_array[x]);
            }
        }
        printf("\n");
    }
//    printf("44444444 %d\n",ad_matrix[0][0]);
//    printf("55555555 %d\n",ad_matrix[0][2]);
    printf("\n");
    for (int q = 0; q <number; q++) {
        max_chain[q] = 1;
        chain_position[q][0] = 0;
        d[q] = 0;
    }
//    printf("666666 %d\n",max_chain[0]);
       for (int p =number-1 ; p >= 0; p--) {
         max_length = 1;
        for (int w = p + 1; w <number; w++) {
            if (ad_matrix[p][w] == 1) {
                if (max_length < max_chain[w] + 1) {
                    max_length = max_chain[w] + 1;
                    chain_position[p][0] = 1;
                    chain_position[p][1] = w;
                    
                }
                else {
                    if (max_length == max_chain[w] + 1) {
                        chain_position[p][0] = chain_position[p][0] + 1;
                        chain_position[p][chain_position[p][0]] = w;
                    }
                }
                
            }
        }
        max_chain[p] = max_length;
    }
    max_length = 0;
    for (int s = 0; s <number; s++) {
        if (max_length< max_chain[s])
            max_length = max_chain[s];
    }
    
    printf("Maximum chain length: %d\n", max_length);
    printf("Maximal chains:\n");
    for (int s = 0; s <number; s++) {
        if (max_length == max_chain[s]) {
            d[1] = s;
            Longest(s, 1);
        }
    return 0;
    }
}
//Time complexity analysis
//Task1:Tn this part,the time complexity is n*n,because we need to search each
//Task 1:In this part,the time complexity is n*n.Because we need to search each input word(n) and then compare it with the following (n-1) words.If thef ollowing wird just has one different with current word then it can link to the current word.
//Task 2:The maximum length of a word chain that can be built from the given words,all word chains of maximum length that can be built from the given words.                                                                    In this part,the time complexity is n*n.                               Because I tryed to find the maxmum chain from tail to head,so we need to dearch all words(n) and confirm that whether the prevoius word(n-1) links the current word.After that I will store the link nodes and number of this word in a adjacency matrix.And then search in this matrix to find max chain length.
















