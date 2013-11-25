#include <stdio.h>
/*
 *	Linked link of linked lists
 *
 */
struct node {
	/* 
	 * Doubly Linked
	 */
	// Heat node pointer of it's own
	struct node * head ; 
	// Next node pointer of it's own
	struct node * next ;
};
struct node *del_every_other_node(struct node * head ) {
	struct node *ptr->head  ; 
	int curr_node_index = 0 ;
	
	while(ptr!= NULL){
		if (curr_node_index%2 == 1 ){
			struct node * temp = ptr->next ; 
			ptr->next = temp->next  ; 
			free (temp) ; 

		}
		ptr = ptr->next ; 
	}

	return head ;  // 
}
int main(){
	
}
