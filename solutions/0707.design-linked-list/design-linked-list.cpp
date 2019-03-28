/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 *
 * https://leetcode.com/problems/design-linked-list/description/
 *
 * algorithms
 * Easy (23.58%)
 * Total Accepted:    22.1K
 * Total Submissions: 93.7K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * Design your?implementation of the linked list. You can choose to use the
 * singly linked list or the doubly linked list. A node in a singly?linked list
 * should have two attributes: val?and next. val is the value of the current
 * node, and next?is?a?pointer/reference to the next node. If you want to use
 * the doubly linked list,?you will need?one more attribute prev to indicate
 * the previous node in the linked list. Assume all nodes in the linked list
 * are 0-indexed.
 * 
 * Implement these functions in your linked list class:
 * 
 * 
 * get(index) : Get the value of?the index-th?node in the linked list. If the
 * index is invalid, return -1.
 * addAtHead(val) : Add a node of value val?before the first element of the
 * linked list. After the insertion, the new node will be the first node of the
 * linked list.
 * addAtTail(val) : Append a node of value val?to the last element of the
 * linked list.
 * addAtIndex(index, val) : Add a node of value val?before the index-th?node in
 * the linked list.?If index?equals?to the length of?linked list, the node will
 * be appended to the end of linked list. If index is greater than the length,
 * the node will not be inserted.
 * deleteAtIndex(index) : Delete?the index-th?node in the linked list, if the
 * index is valid.
 * 
 * 
 * Example:
 * 
 * 
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
 * linkedList.get(1);            // returns 2
 * linkedList.deleteAtIndex(1);  // now the linked list is 1->3
 * linkedList.get(1);???         // returns 3
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [1, 1000].
 * The number of operations will be in the range of?[1, 1000].
 * Please do not use the built-in LinkedList library.
 * 
 * 
 */
class MyLinkedList {
  private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int _val) : val(_val), next(nullptr) {}
    };

    ListNode *pre, *cur;
    int size;

  public:
    MyLinkedList() {
        pre = new ListNode(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index > size - 1) return -1;
        cur = pre->next;
        while (index--) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode *n = new ListNode(val);
        n->next = pre->next;
        pre->next = n;
        ++size;
    }

    void addAtTail(int val) {
        cur = pre;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = new ListNode(val);
        ++size;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        ListNode *n = new ListNode(val);
        cur = pre;
        while (index--) cur = cur->next;
        n->next = cur->next;
        cur->next = n;
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > size - 1) return;
        cur = pre;
        while (index--) cur = cur->next;
        cur->next = cur->next->next;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

