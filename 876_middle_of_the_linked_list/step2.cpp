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
// 1,1 -> 2,3 -> 3,5 (fast->next == nullptr)
// 1,1 -> 2,3 -> 3,5 -> 4,nullptr (fast == nullptr)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Return the second node when there are two "middle"s. 1-indexed.
        int middle_index = GetListSize(head) / 2 + 1;
        int index = 1;
        ListNode* node = head;
        while (index != middle_index) {
            ++index;
            node = node->next;
        }
        return node;
    }
private:
    int GetListSize(ListNode* head) {
        int size = 0;
        ListNode* node = head;
        while (node) {
            ++size;
            node = node->next;
        }
        return size;
    }
};
