/*
 * Author: Ethan shi
 * Version: V1.0.0
 * Date: 2016-1-2
 * Description:
 *   this is a solution of 
 * zigzag convertion problem
 * from LeetCode.
 */
#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows);

/*a simple test of convert()*/
int main() {
    char* str = "abcdefghijklmnopqrstuvwxyz";
    printf("%s\n", str);
    printf("%s\n", convert(str, 4));  
}

/*convert string to zigzag fromat string*/
char* convert(char* s, int numRows) {
    int r;              /*index of rows*/
    int len;            /*length of input string*/
    int k;              /*a param equals to (numRows-1)*2*/
    char* out;          /*output string*/
    int outIndex;       /*index of out*/
    if(1 >= numRows)    /*deal with the special case*/
        return s;
    len = 0;            /*the length of input string*/
    k = (numRows-1)*2;  /*the gap of columns*/
    while(s[len] != '\0') {
        len++; 
    }
    out = malloc((len+1)*sizeof(char)); 
    outIndex = 0;
    for(r=0; r<numRows; r++) {           /*fill output string row by row */
        if(r == 0 || r == numRows-1) {   /*first and last row is half as lang as others*/
            int index = r;               /*there is only one index*/
            while(1) {                   /*fill this row until index > len*/
                if(index < len) {       
                    out[outIndex] = s[index];
                    outIndex++;          /*add out string index*/
                } else {
                    break;
                }
                index += k;              /*add a gap to the index*/
            }
        } else {
            int index1 = -r;             /*there are two indexs*/
	    int index2 = r;
            while(1) {                   /*fill this row until index2 > len*/
                if(index1 > 0 && index1 < len) {
                    out[outIndex] = s[index1];
                    outIndex++;          /*add out string index*/
                }
                if(index2 < len) {
                    out[outIndex] = s[index2];
                    outIndex++a;         /*add out string index*/
                } else {
                    break;
                }
                index1 += k;             /*add a gap to the index*/
                index2 += k;             /*add a gap to the index*/
            }
        }
    }
    out[len] = '\0';
    return out;
}
