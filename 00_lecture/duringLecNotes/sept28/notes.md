Objectives 
---------------------
1.  Hash tables
    a.  No replacement
    b.  Linear probing
    c.  Quadratic Probing
    d.  Separate chaining hashing
2.  Other bases


- Can we beat O(log(n)) runtime for insert and delete ?
- Hash table: worst case is worse than O(log(n)). **But**, average
case performance is better 
Hash tables
---------------------
+ Hash Table is an array and a hash function, for the most part.
+ Need to make our array bigger than the number of records we think we might store

? How to decide where to store a piece of data that's inserted
Ans. We use a hash function 

+ What is a hash function?
    - It's a function that takes on any valid data to insert and returns and integer from 0 to n-1 where n=TABLESIZE
        - This is where the record is stored 
    - Properties of a good hash function    
        1. Fast 
        2. Given any input, the chance it ends up in any index ; should be close to 1/n

    - Big Prob: what if f(a)=f(b)? (when a!=b)
        - How to deal with this?
            1. No replacement: copy over old records + lose data 
            2. Linear Probing: 
                - If I want to insert s,
                    a. Calculate f(s). Let i = f(s)
                    b. While (table[i] != NULL )
                        i = (i+1)%n;
                    + Could be slow if table is close to being filled!
            3. Quadratic Probing
                - Try indexes m in the following order
                    Let i = f(s)
                        i, i+1, i+4,i+9,i+16
                    pseudocode 1
                        while ( table[i] != NULL){
                            i=(i+j)%n
                            j+=2
                        }
                    pseudocode 2 
                        int saveI = i , j = 1 ; 
                        while ( table[i]!=NULL){
                            i = (savei+j*j)%n
                            j++ ; 
                        }

