October 31, 2013
Computer Science Exam #3 Overview


Exam #3 Topics
=====================
- [x] Stacks
  - [x] Array implementation
  - [x] Linked List Implementation
  - [x] Run times of each operation
    - All operations are of O(1)
- [x] Queues
  - [x] Array Implementation
  - [x] Linked List implementation
  - [x] Run times of each operation ( for multiple implementaitons )
    - Linked List Insert (O(n) with single pointer to front, O(1) if pointer to both front and back)
    - Array Insert (O(1))
    - Push O(1)
- [x] Binary Trees
  - [x] Traversals 
    - Depth-First Traversal
      - Inorder,postorder,preorder
  - [x] Insert:  O(1) Best, O(log(n)) average, O(n) worst
  - [x] Search:  O(1) Best, O(log(n)) average, O(n) worst
  - [x] Delete:  O(1) Best, O(log(n)) average, O(n) worst
    - Target with no child
    - Target with one child
    - Target with two children
      - Find Largest node in target->left OR
      - Find Smallest node in target->right
  - [x] Writing General Function
  - [x] Analysis ( Best Case, Average Case, Worst Case )
    - Binary Search: Best case O(1), O(log(n)) Average, O(n) Worst
      
- [x] AVL Trees
  - [ ] Definition
  - [~] Insert
  - [~] Delete 
  - [ ] Analysis
- [ ] Binary Heaps
  - [ ] Definition
  - [ ] How to Store
  - [] Insert 
  - [ ] Delete Min
- [ ] Hash Tables
  - [ ] Linear probing strategy for collisions
  - [ ] Quadratic Probing Strategy for collisions
  - [ ] Separate Chaining Hashing Strategy for collisions
- [ ] Base Conversion
  - [x] Any base to base 10
    - AF5 = 10*16^2+15*16^1+5*16^0
  - [x] Base 10 to any base
    - Divide, remainder, keep least significant
  - [x] Converting between bases that are perfect powers of 2
    - Figure out groups of bits to represent each digit by using g=log(n)
    - Write each digit by g number of bits.

