/*
 * Author: Ethan Shi
 * Version: V1.1.0
 * Date: 2016-1-4
 * Description:
 *   this is a solution of 
 * "Longest Substring Without Reoeating Characters"
 * and a simple test.
 */

#include <stdio.h>
#include <string.h>

int main() {
	char* str = "abcddddaacds";
	int l = lengthOfLongestSubstring(str);
	printf("%d\n",l);
}

/*find the longest sub string without repeating of input*/
int lengthOfLongestSubstring(char* s) {
    int index[127];		/*record a char's index in the input string*/
	int start = 0;
	int end = 0;
    int count = 0;		/*count of without repeating characters*/
    int max = 0;		/*max of all counts*/
    memset(index, -1, sizeof(index));		/*initalize the array*/
    while(s[end] != '\0') {		/*read inputs*/
        char c = s[end];
        if(index[c] < start) {	/*no repeat*/
            count++;
        }
        else {					/*repeated*/
            if(count > max) {	/*save the max length*/
                max = count;
            }
            count = start+count-index[c];
			start = index[c]+1;
        }
        index[c] = end;
		end++;
	}
    if(count > max) {						/*consider the langest substring is at last*/
        max = count;
    }
    return max;
}
