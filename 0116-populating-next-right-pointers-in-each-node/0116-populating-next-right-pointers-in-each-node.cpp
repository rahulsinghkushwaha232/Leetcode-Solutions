class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* leftmost = root;

        while (leftmost->left != nullptr) {
            Node* head = leftmost;

            while (head != nullptr) {
                head->left->next = head->right;

                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }

                head = head->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};