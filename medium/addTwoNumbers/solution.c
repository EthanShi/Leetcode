/*
 * Author: Ethan Shi
 * Version: V1.0.0
 * Date: 2016-1-3
 * Description:
 *  this is a solution of "add two numbers" question
 *  and a simple test function main().
 */

 #include <stdio.h>
 #include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2); 

 int main() {
    struct ListNode* ans;
    struct ListNode* l1;
    struct ListNode* l2;
    struct ListNode* l1t;
    struct ListNode* l2t;
    int num1[10] = {1,2,3,4,0,0,0,0,0,0};
    int num2[10] = {3,5,2,1,0,0,0,0,0,0};
    int i;
    l1 = malloc(sizeof(struct ListNode));
    l2 = malloc(sizeof(struct ListNode));
    l1->val = num1[0];
    l2->val = num2[0];
    l1t = l1;
    l2t = l2;
    for(i=1; i<10; i++) {
        l1t->next = malloc(sizeof(struct ListNode));
        l2t->next = malloc(sizeof(struct ListNode));
        struct ListNode* tmp1 = l1t->next;
        struct ListNode* tmp2 = l2t->next;
        tmp1->val = num1[i];
        tmp2->val = num2[i];
        tmp1->next = NULL;
        tmp2->next = NULL;
        l1t = tmp1;
        l2t = tmp2;
    }
    ans = addTwoNumbers(l1,l2);
    for(i=0; i<10; i++) {
        printf("%d,",ans->val);
        ans = ans->next;
    }
    printf("\n");
 }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* answerHead;
    struct ListNode* answerTail;
    int i = 0;
    int c = 0;
    answerHead = malloc(sizeof(struct ListNode));
    answerTail = answerHead;
    while(NULL != l1 && NULL != l2) {
        answerTail->next = malloc(sizeof(struct ListNode));
        struct ListNode* tmp = answerTail->next;
        int sum = l1->val+l2->val+c;
        tmp->val = sum>=10?sum-10:sum;
        tmp->next = NULL;
        c = sum>=10?1:0;
        l1 = l1->next;
        l2 = l2->next;
        answerTail = tmp;
    }
    
    if(NULL != l2)
        l1 = l2;
        
    while(NULL != l1) {
        answerTail->next = malloc(sizeof(struct ListNode));
        struct ListNode* tmp = answerTail->next;
        int sum = l1->val+c;
        tmp->val = sum>=10?sum-10:sum;
        tmp->next = NULL;
        c = sum>=10?1:0;
        l1 = l1->next;
        answerTail = tmp;
    }
    
    if(c) {
        answerTail->next = malloc(sizeof(struct ListNode));
        struct ListNode* tmp = answerTail->next;
        tmp->val = 1;
        tmp->next = NULL;
     }
     return answerHead->next;
}
