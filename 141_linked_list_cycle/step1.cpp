/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 #include <set>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::set<ListNode*> visited;
        ListNode* node = head;
        while (node != nullptr) {
            if (visited.contains(node)) {
                return true;
            }
            visited.insert(node);
            node = node->next;
        }
        return false;
    }
};
