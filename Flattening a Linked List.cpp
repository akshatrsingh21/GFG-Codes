/* Node structure
struct Node {
    int data;
    Node* next;
    Node* bottom;
};
*/

class Solution {
public:
    
    // Merge two sorted linked lists using bottom pointer
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL; // Important
        return result;
    }

    // Function to flatten the linked list
    Node* flatten(Node* root) {
        if (!root || !root->next)
            return root;

        // Recur for list on right
        root->next = flatten(root->next);

        // Merge current list with right list
        root = merge(root, root->next);

        return root;
    }
};
