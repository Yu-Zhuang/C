//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *last;
    last=NULL;
    while(head){
        struct ListNode *next=head->next;
        head->next=last;
        last=head;
        head=next;
    }
    return current;
}
