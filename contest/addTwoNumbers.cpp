#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode();  // Create a dummy node to simplify handling the result
        ListNode *current = dummy;         // Pointer to the current node in the result

        int carry = 0;  // Initialize carry to 0

        // Loop until either l1 or l2 has remaining digits or there's a carry
        while (l1 || l2 || carry) {
            // Sum the current digits along with the carry
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;

            // Update carry for the next calculation
            carry = sum / 10;

            // Create a new node with the sum % 10 and move the current pointer
            current->next = new ListNode(sum % 10);
            current = current->next;

            // Move to the next digits in l1 and l2 if they exist
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;  // Skip the dummy node and return the actual result
    }
};

int main() {
    // Example usage
    Solution solution;

    // Create two linked lists representing numbers
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // Call the addTwoNumbers function
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // Print the result
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
