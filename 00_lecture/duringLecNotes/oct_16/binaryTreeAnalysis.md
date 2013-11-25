Binary Tree Analysis
------------

### All functions that been analyzed is of one of two categories
    1. Go down one tree path 
        - Insert
        - Delete
        - Search 
    2. Go down both paths recursively
        - Traversals
        - Other random functions
        > - Visit Every node (Potentially)
        > - O(n) where n = number of nodes in tree or
        > - O(h) where h is the height of the tree 

#### More on category 2
    - What is the range of h?
        - *Worst case*: A Line of some sore where all nodes are to the left only.
                   2
                  /
                 2
                /
               1
              /
             0

        - *Best case*: Complete Binary Tree (a binary tree with each level filled in completely)
                               | Level | Height
                2              |   0   |   1
               /  \            |   1   |   2
              2    3           |   2   |   3
             / \  / \          |   3   |   4 
            1  2 2   1         |   4   |   5
            
            - Each level is of power 2. 
            - Total Number of nodes in tree = ${2^{n+1}-1}
            - ${h=\log_2(n+1)-1}

#### AVL Tree - Balance Binary Tree
    - In addition to the binary search tree property, all AVL trees adhere to the following properties
        1. For each node in the tree, the heights of the left and right tree cannot differ by more than 1
                         20     Invalid
                        /  \
                       1    

                         20     Valid
                        /  \
                       1    5

                         20     Valid
                        /  \
                       1    5
                      /    /
                     0    4   

                         20     Invalid
                        /  \
                       1    5
                      / \   /
                     0   2 4   

                         20     valid for 5 branch with height 1, valid for 1 branch of height 3 
                        /  \
                       1     5
                      / \   / \
                     0   2,4   10
                      \
                       5

        - T >= T(n-1) + T(n-2) + 1 where T(0)=1 and T(1)=2
                                    T(n)=F_{n+3}-1
        - If this ^ property can be satisfied, the height h of the tree will equal O(log(n))  where n is the number of nodes.

    - How do we maintain these properties?
        > Steps for Insert
            1. Do regular ""binary search tree" insert. If valid AVL tree, do nothing

            2. (On Paper Method) Create a label for each level
                        2    A
                       /     
                      12      B
                     /
                    3        C
               How to restructure+which node to restructure
                    a. Trace up the ancestral path (bottom up) from the newly inserted node finding the *first* imbalanced node (may be on test)
                    b. Once the node is found, rebalance at that node as described above, reattaching the subtrees in their valid binary search tree 
                       places

