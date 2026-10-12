class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* clonedHead = head->next;
        Node* clonedCurr = clonedHead;
        while (curr) {
            curr->next = clonedCurr->next;
            curr = curr->next;
            if (curr) {
                clonedCurr->next = curr->next;
                clonedCurr = clonedCurr->next;
            }
        }

        return clonedHead;
    }
};