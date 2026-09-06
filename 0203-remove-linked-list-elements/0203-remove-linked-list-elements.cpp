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
class Solution {
public:
    ListNode* remove(ListNode* prev)
    {
        if (prev == nullptr)
            return nullptr;

        ListNode* to_delete = prev->next;
        if (to_delete != nullptr)
        {
            prev->next = to_delete->next;
            delete to_delete;
        }

        return prev;
    }

    ListNode* removeElements(ListNode* head, int val) {

        if (head == nullptr)
            return head;

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->val == val && temp != head)
                temp = remove(prev);

            prev = temp;
            temp = temp->next;
            
        }

        if (head->val == val)
        {
            ListNode* temp = head;
            head = temp->next;
            delete temp;
        }

        return head;
    }
};