/*
 * Author: Ethan Shi
 * Version: V1.0.0
 * Date: 2016-1-4
 * Description:
 *   this is a solution of 
 * "Longest Substring Without Reoeating Characters"
 * and a simple test.
 */

#include <stdio.h>

int main() {
	char* str = "abcddddaacds";
	int l = lengthOfLongestSubstring(str);
	printf("%d\n",l);
}

/*find the longest sub string without repeating of input*/
int lengthOfLongestSubstring(char* s) {
    char* in = s;
    int index[127];		/*record a char's index in the input string*/
    int used[127];		/*record used indexs of index[]*/
    int uc = 0;			/*used count*/
    int count = 0;		/*count of without repeating characters*/
    int max = 0;		/*max of all counts*/
    int i;
    for(i=0; i<127; i++) {		/*initalize the array*/
        index[i] = -1;
        used[i] = -1;
    }
    i=0;
    while(in[i] != '\0') {		/*read inputs*/
        char c = in[i];
        if(index[c] == -1) {	/*no repeat*/
            index[c] = i;
            count++;
            used[uc] = c;
            uc++;
        }
        else {					/*repeated*/
            int j = 0;
            int rpi = index[c]; /*repeated character's index*/
            if(count > max) {	/*save the max length*/
                max = count;
            }
            while(used[j] != -1) {			/*clear index[] accroding to used[]*/
                int idx = used[j];
                if(index[idx] < rpi) {		/*only clear characters before rpi*/
                    index[idx] = -1;
                    uc--;
                    used[j] = used[uc];		/*concentrate item of used[]*/
                    used[uc] = -1;
                    count--;				/*adjust count*/
                } else {
                    j++;
                }
            }
            index[c] = i;
        }
        i++;
    }
    if(count > max) {						/*consider the langest substring is at last*/
        max = count;
    }
    return max;
}
