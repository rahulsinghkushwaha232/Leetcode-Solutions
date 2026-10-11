class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;
        Node* head = nullptr;
        Node* tail = nullptr;

        while (curr != nullptr) {
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    if (tail != nullptr) {
                        tail->next = curr->left;
                    } else {
                        head = curr->left;
                    }
                    tail = curr->left;
                }
                if (curr->right != nullptr) {
                    if (tail != nullptr) {
                        tail->next = curr->right;
                    } else {
                        head = curr->right;
                    }
                    tail = curr->right;
                }
                curr = curr->next;
            }
            curr = head;
            head = nullptr;
            tail = nullptr;
        }

        return root;
    }
};