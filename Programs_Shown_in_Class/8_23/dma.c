// Sean Szumlanski (Guest Lecturer)
// COP 3502
// August 23, 2013

// Dynamic Memory Allocation (and a bit about pointers and dereferencing)

// Summary of Key points:
//
// 1. A pointer is just a certain type of container. It holds addresses of
//    variables!
//
// 2. Every variable has an address. You can see them like so:
//
//       int i = 53;
//       printf("%p\n", &i);
//                ^ This is the conversion code used to print pointers
//
// 3. Check out the diagrams in the code below to see how the contents of
//    memory change after different statements are executed.
//
// 4. Segmentation Faults are caused by attemping to go somewhere in memory
//    where you're not supposed to be! A common cause of this is dereferencing
//    an uninitialized pointer, which contains gobbledygook!
//
//       int *p;
//       *p = 42;
//        ^ Where does p point to? Somewhere random(ish)! This will most likely
//          cause a segmentation fault!
//
// 5. Sometimes we want to create an array of arbitrary size at runtime. How we
//    acomplish that using malloc() is the main take-away from today's lecture.
//    (In class, we defined "static" vs. "dynamic" memory allocation.)
//
// 6. When we're no longer using a variable we allocated dynamically, we need to
//    free() it!
//
// 7. We saw that pointers are a lot like arrays, and arrays are a lot like
//    pointers.


#include <stdio.h>
#include <stdlib.h> // herein resides malloc()

int main(void)
{
	// We didn't use all these variables. I just declared a bunch of them to
	// drive home the "square peg, round hole" analogy.
	int i = 42;
	double f = 3.14159;
	char c = 'c';
	
	// We'll use these later. I'm just a bit old school, and I insist on
	// declaring all my variables in C at the top of each function.
	int array[10];
	int n;
	
	// A pointer is a memory address! That is its sole purpose in life: to hold
	// memory addresses!
	int *p;
	
	// This is what memory might look like right now. Notice that i and p are
	// boxes in memory, designed to hold data, each with a unique memory address:
	//
	// p       0x181  i  0x193
	// +-----------+  +------+
	// | (garbage) |  | 42   |
	// +-----------+  +------+
	//
	// (I made those memory addresses up.)
	
	// At this point, dereferencing p can cause a segfault. The dereference
	// operator says, "p hold an address. GO to that address (and mess with the
	// data that's stored there)!" This is a bad idea if the address stored in
	// p is gobbledygook. Who know where we might end up?!
	//*p = 41;
	
	// This makes more sense: first, put the address of i in p:
	p = &i;
	
	// Now, memory looks like this:
	//
	// p   0x181  i  0x193
	// +-------+  +------+
	// | 0x193 |  | 42   |
	// +-------+  +------+
	
	*p = 41;
	
	// Notice that when we print &i and p, those are the same!
	// Notice also that &i and &p are different, and that i now has value 41.
	printf("%p\n", &i);
	printf("%p\n", &p);
	
	printf("%p\n", p);
	printf("%d\n", i);
	
	// What if we want to leave i be, and create a new integer box?! Like this:

	// p   0x181  i  0x193     0x297
	// +-------+  +------+  +------+
	// | 0x193 |  | 41   |  |      |
	// +-------+  +------+  +------+
	
	// This is DYNAMIC MEMORY ALLOCATION. We can do it with a function called
	// malloc().
	//
	// When we call malloc(), we need to know two things:
	// a) how big is the box we want to create?
	// b) how many such boxes should it create?
	// ^ multiply these two to get the overall amount of memory to set aside
	
	// malloc() returns the address of the newly allocated space. Notice that
	// the new box doesn't have a variable name. So, how will we access it?
	// (Correct! We'll store the address in p!)
	
	// Check your understanding: Which of these is correct?
	//*p = malloc(sizeof(int));
	//&p = malloc(sizeof(int));
	p = malloc(sizeof(int));

	//       ^ sizeof() takes a DATA TYPE as its argument and tells us how much
	//         space that data type takes up in memory! (This is essentially
	//         multiplied by 1 in this example, because we only want one integer
	//         box.)
	
	// Memory now looks like this(ish):
	//
	// p   0x181  i  0x193     0x297
	// +-------+  +------+  +------+
	// | 0x297 |  | 42   |  |      |
	// +-------+  +------+  +------+
	
	*p = 53;
	
	// p  0x181  i  0x193     0x297
	// +------+  +------+  +------+
	// |0x297 |  | 42   |  | 53   |
	// +------+  +------+  +------+
	
	printf("%d\n", *p);
	
	// ^ NOTE: We came back to this line after looking at the array stuff below
	//         and saw that it is equivalent to:  printf("%d\n", p[0]);
	
	// Now, what if we execute this statement to create space for 10 integers:
	//
	//      p = malloc(sizeof(int) * 10);
	//
	// THIS IS AN EMERGENCY! We lost our reference to 0x297,
	// and it's still free-floating in memory! This is called a
	// MEMORY LEAK and is a BIG DEAL (especially when dealing with
	// LOTS of dynamically allocated memory). If we have huge memory
	// leaks, memory can fill up quickly and slow down our programs!
	
	// To avoid memory leaks, we first free the memory we will no longer
	// be using:
	free(p);
	
	// NOW we can overwrite the value stored in p
	p = malloc(sizeof(int) * 10);
	
	// malloc() returns the address of the FIRST int in this block.
	// malloc ensures that these integers are CONTIGUOUS in memory.
	
	// Well, that was FANCY AS ALL GET-OUT, but how do we access
	// all ten of those elements?
	
	// We can treat p as an array!
	for (i = 0; i < 10; i++)
		p[i] = i * 10;
	
	for (i = 0; i < 10; i++)
		printf("%d ", p[i]);
	printf("\n");
	
	// Suppose I do: int array[10];
	// What is 'array' without any index? It's the base address of the array!
	// If that's true, the following lines should print the same thing:
	printf("%p\n", array);
	printf("%p\n", &(array[0])); 
	
	// Note: We should never do this in C:
	//
	//    int array[n];
	//
	// ...unless n is #defined somewhere. If n is a variable, we need DMA!
	//
	// For example:
	
	printf("How many integers do you want in your new array? ");
	scanf("%d", &n);
	
	// NOTE: We have a memory leak here! We didn't free the previous array first!
	//       Check your understanding: How would you prevent this memory leak?
	p = malloc(sizeof(int) * n);
	
	// Now, how do we free this array?
	free(p);
	// ^ NOTE: That gets rid of the whole darn array! All n elements!
	
	// Once we free a chunk of dynamically allocated memory, it's good practice
	// to get rid of any references to that old address. If we want to signal
	// that our pointer is no longer pointing to something of value, we use:
	p = NULL;
	
	// (It's also good practice to initialize unused pointers to NULL.)
	
	return 0;
}