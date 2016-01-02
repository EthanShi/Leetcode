/*
 * this is a solution of 
 * zigzag convertion problem
 * from LeetCode
 */
#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows);

int main() {
    char* str = "abcdefghijklmnopqrstuvwxyz";
    printf("%s\n", str);
    printf("%s\n", convert(str, 4));  
}


char* convert(char* s, int numRows) {
    int r;      //index of rows
    int len;    //length of input string
    int k;      //a param equals to (numRows-1)*2
    char* out;   //output string
    int outIndex;//index of out
    if(1 >= numRows)
        return s;
    len = 0;
    k = (numRows-1)*2;
    while(s[len] != '\0') {
        len++; 
    }
    out = malloc((len+1)*sizeof(char));
    outIndex = 0;
    for(r=0; r<numRows; r++) {
        if(r == 0 || r == numRows-1) {
            int index = r;
            while(1) {
                if(index < len) {
                    out[outIndex] = s[index];
                    outIndex++;
                } else {
                    break;
                }
                index += k;
            }
        } else {
            int index1 = -r;
	    int index2 = r;
            while(1) {
                if(index1 > 0 && index1 < len) {
                    out[outIndex] = s[index1];
                    outIndex++;
                }
                if(index2 < len) {
                    out[outIndex] = s[index2];
                    outIndex++;
                } else {
                    break;
                }
                index1 += k;
                index2 += k;
            }
        }
    }
    out[len] = '\0';
    return out;
}
