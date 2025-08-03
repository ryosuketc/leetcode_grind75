/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode sentinel;
        ListNode* tail = &sentinel;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (list1) {
            tail->next = list1;
        }
        if (list2) {
            tail->next = list2;
        }
        return sentinel.next;
    }
};

// 引数と同じ名前を使わない
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode sentinel;
        ListNode* tail = &sentinel;
        ListNode* list1_pointer = list1;
        ListNode* list2_pointer = list2;
        while (list1_pointer != nullptr && list2_pointer != nullptr) {
            if (list1_pointer->val < list2_pointer->val) {
                tail->next = list1_pointer;
                list1_pointer = list1_pointer->next;
            }
            else {
                tail->next = list2_pointer;
                list2_pointer = list2_pointer->next;
            }
            tail = tail->next;
        }
        if (list1_pointer) {
            tail->next = list1_pointer;
        }
        if (list2_pointer) {
            tail->next = list2_pointer;
        }
        return sentinel.next;
    }
};


class Solution3 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode sentinel;
        ListNode* tail = &sentinel;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return sentinel.next;
    }
};
