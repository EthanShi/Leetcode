/*
 * Author: Ethan Shi
 * Version: 1.0.0
 * Date: 2016-1-3
 * Description:
 *   this is a solution of the question called "TwoSum".
 *   see question.md for more details.
 */
 
#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct Node *(table[SIZE]);

int* twoSum(int* nums, int numsSize, int target);
void initTable();
void freeTable();
void freeNode(struct Node* node);
void addNode(int key, int value);
int findValue(int key, int index);

int main() {
    initTable();
    int data[10] = {1,2,3,4,5,6,7,8,9,10};
    int* index = twoSum(data, 10, 3);
    printf("%d,%d\n",index[0],index[1]);
    free(index);
    return 0;
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * this function use a simple hash table to solve the question.
 */
 int* twoSum(int* nums, int numsSize, int target) {
    int* answer = malloc(2*sizeof(int));
    int i;
    for(i=0; i<numsSize; i++) {         /*fill table*/
        addNode(nums[i],i);
    } 
    for(i=0; i<numsSize; i++) {         /*find value*/
        int diff = target-nums[i];     /*calculate the value to be found*/
        int value = findValue(diff,i); 
        if(-1 != value) {
            answer[0] = i+1;
            answer[1] = value+1;
            break;
        }
    }
    freeTable();
    return answer;
 }

/*initialize table*/
void initTable() {
    int i;
    for(i=0; i<SIZE; i++) {
        table[i] = NULL;
    }
}

/*free malloced memory*/
void freeTable() {
    int i;
    for(i=0; i<SIZE; i++) {
        freeNode(table[i]);
    }
}
void freeNode(struct Node* node) {
    if(node == NULL)
        return;
    if(NULL != node->next)
        freeNode(node->next);
    else {
        free(node);
        node = NULL;
    }
}

/*
* add a key-value node to table
* this table use chain to solve conflict
*/
void addNode(int key, int value) {
    unsigned int hash = key;
    hash = hash%SIZE;
    struct Node* node = malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    if(NULL == table[hash]) {
        table[hash] = node;
    } else {
        node->next = table[hash];
        table[hash] = node;
    }
}

/*find a key-value node from table*/
int findValue(int key, int index) {
    unsigned int hash = key;
    hash = hash%SIZE;
    struct Node* tmp = table[hash];
    while(NULL != tmp) {
        if(tmp->key == key && tmp->value != index)  {
            return tmp->value;
        }
        tmp = tmp->next;
    }
    return -1;
}
