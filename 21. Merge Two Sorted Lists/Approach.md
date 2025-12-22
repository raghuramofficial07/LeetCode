<!-- GitHub Project Banner -->

<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/DSA-black?labelColor=black&color=black">
  <img src="https://img.shields.io/badge/Built%20by-RaghuRam-black?labelColor=black&color=black">
</p>

# Merge Two Sorted Linked Lists

## » Table of Contents

* Introduction
* Problem Statement
* Learner’s Approach
* Algorithm Breakdown
* Reference Implementation
* Complexity Analysis
* Key Takeaways
* Author Footer

---

## » Introduction

Merging two sorted linked lists is a foundational Data Structures problem that evaluates pointer handling, traversal logic, and understanding of linked list mechanics.

This documentation presents a **learner-friendly, mono-chrome approach** that prioritizes clarity and correctness over premature optimization.

---

## » Problem Statement

Given two sorted linked lists `l1` and `l2`, merge them into one sorted linked list and return the head of the new list.

---

## » Learner’s Approach

The solution uses a **dummy node technique** to simplify edge-case handling while building a new linked list.

Instead of rearranging existing nodes, this approach:

* Creates new nodes
* Appends them in sorted order
* Preserves original lists

This makes the logic easier to reason about, especially for beginners.

---

## » Algorithm Breakdown

1. Create a dummy node as a fixed starting reference
2. Maintain a `tail` pointer to build the merged list
3. Traverse both lists simultaneously
4. Compare current node values
5. Append the smaller value as a new node
6. Advance the corresponding pointer
7. Append remaining nodes once one list ends
8. Return `dummy->next` as the merged list head

---

## » Reference Implementation

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                tail->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            tail = tail->next;
        }

        while (l1 != nullptr) {
            tail->next = new ListNode(l1->val);
            tail = tail->next;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            tail->next = new ListNode(l2->val);
            tail = tail->next;
            l2 = l2->next;
        }

        return dummy->next;
    }
};
```

---

## » Complexity Analysis

| Metric           | Value       |
| ---------------- | ----------- |
| Time Complexity  | O(n + m)    |
| Space Complexity | O(n + m)    |
| Traversal        | Single Pass |

Where:

* `n` is the length of list `l1`
* `m` is the length of list `l2`

---

## » Key Takeaways

* Dummy nodes simplify linked list problems
* Tail pointers help build lists incrementally
* Single-pass traversal ensures efficiency
* Creating new nodes is safer for beginners

---

## » Author Footer

**Created By:** Vemparala Sri Satya RaghuRam
**License:** MIT
**Domain:** Data Structures & Algorithms (C++)

<p align="left">
  <img src="https://img.shields.io/badge/%23BeyondCertifications-black?logo=tag&logoColor=white&labelColor=black&color=black">
  <img src="https://img.shields.io/badge/%23IndustryOriented-black?logo=tag&logoColor=white&labelColor=black&color=black">
  <img src="https://img.shields.io/badge/%23CodeWithRaghuRam-black?logo=tag&logoColor=white&labelColor=black&color=black">
</p>
