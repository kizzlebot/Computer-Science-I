#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char filename[] = "bigInt.txt";
struct charIn {
	char * aProb1 ;
	char * aProb2 ; 
	int size1 ; // number of elements + the null
	int size2 ; 
};
struct integer {
	int * digits ; 
	int size ; 
};


void printInt(int n );
int getNumProbs(FILE * file);
struct charIn ** readIn(FILE * file, int numProbs );
char * stripLead(char * stringInt);
struct integer * convert_integer(char* stringInt);
void print(struct integer *);
struct integer * multiply(struct integer * p , struct integer * q);
int main(){
	// Open file for reading
	FILE * file  = fopen(filename, "r"); 
	int numProbs = getNumProbs(file) ; 
	// readIn everything
	struct charIn ** redIn = readIn(file,numProbs);
	// close the file
	fclose(file);

	int i = 0 ; 
	// malloc intIn
	struct integer ** IntIn = malloc(sizeof(struct integer *)*numProbs);
	int j = 0 ; 
	while ( redIn[j] != NULL){
		// Strip the leading 0's 
		redIn[j]->aProb1 = stripLead(redIn[j]->aProb1) ; 
		redIn[j]->aProb2 = stripLead(redIn[j]->aProb2) ; 
		
		// get a struct for each index which contains a digits array and a size
		IntIn[i] = convert_integer(redIn[j]->aProb1);
		IntIn[i+1] = convert_integer(redIn[j]->aProb2);
		//print(IntIn[i]);

		IntIn[i] = multiply(IntIn[i],IntIn[i+1]);
		
		//print(IntIn[i+1]);
		i+=2 ;
		j+=1 ; 
	}

	free(redIn);
	
	return 0 ; 
}
struct integer * multiply(struct integer * p , struct integer * q) {
	int carry = 0 ; 
	struct integer * a = NULL ;

	struct integer * r = malloc(sizeof(struct integer));
	r->digits = calloc(p->size+q->size,sizeof(int));
	
	// Make sure that p has more digits than q
	int p1 = 0 ; 
	int q1= 0 ; 

	int temp ;

	int count = 0 ;
	r->size = q->size+p->size; 
	for ( q1 = 0 ; q1 < q->size ; q1++ ){
		for ( p1 = 0 ; p1 < p->size ; p1++){
			// multiply q->digits with p->digits and add carry  
			temp = r->digits[p1+q1]+p->digits[p1]*q->digits[q1]+carry ; 
			//printf("(q->digits[%d] * p->digits[%d] + carry)\\10 = r->digits[%d+%d]\t Temp = %d", q1,p1,q1,p1,temp); 
			r->digits[p1+q1] = temp%10 ; 
		  	//printf("\n(    %d         *      %d       +   %d )\\10 = %d\n\n", q->digits[q1],p->digits[p1],carry, r->digits[p1+q1]); 
			carry = temp / 10 ; 
	      	//printf("\nCarry = %d \n",carry);
			count++ ;
		}
		if (q1 == q->size-1 && p1 == p->size-1){
			r->digits[r->size-2] += carry ;
			//printf("\ncarry: %d",carry);
			//printf("\nr->digits %d: %d",r->size,r->digits[r->size]) ;
			//printf("\nr->digits %d: %d",r->size-1,r->digits[r->size-1]) ;
			//printf("\nr->digits %d: %d",r->size-2,r->digits[r->size-2]) ;
			//printf("\nr->digits %d: %d",r->size-3,r->digits[r->size-3]) ;
			//printf("\nr->digits %d: %d",r->size-4,r->digits[r->size-4]) ;
			//printf("\nr->digits %d: %d",r->size-5, r->digits[r->size-5]) ;
		}
		carry = 0 ;
	}
	//printf("\nThe Count: %d, p-size:%d q-size: %d",count,p->size,q->size );
	//print(r) ; 	
	return r ; 
}
void print (struct integer *p){
	int n = 0 ; 
	printf("\n");
	for ( n = p->size-1 ; n>-1 ; n--){
		printf("%d",p->digits[n]);
	}
}
char * stripLead(char * stringInt){
	int n = 0 ; 
	while ( stringInt[n]=='0'){
		if ( stringInt[n+1] == '\0'){
			break ; 
		}else {
			stringInt+=1 ; 
		}
	}
	return stringInt ; 
}
struct integer * convert_integer(char* stringInt){
	int i = 0 ; 
	struct integer * p = malloc(sizeof(struct integer));

	while (stringInt[i]!='\0'){
		i++ ; 
	}
	p->digits = malloc(sizeof(int)*i);
	int n = 0 ; 
	//printf("\nPrinting from conver_integer!\n" );
	for ( i-=1 ; i > -1 ; i-- ){
		p->digits[n] = stringInt[i]-'0' ; 
		//printf("%d",p->digits[n]);
		n++ ; 
	}
	p->size = n ; 
	//printf("\nSize: %d",p->size );
	return p ; 
}

void printInt(int n ){
	printf("\nSize :%d",n);
}
int getNumProbs(FILE * file){
	int numProbs ; 
	fscanf(file, "%d", &numProbs );
	return numProbs ; 
}
struct charIn ** readIn(FILE * file, int numProbs ){
	
	int buffer1 = 30 ; 
	int count ;
	
	// malloc that many pointers that points to structures
	struct charIn ** pointToPoint  = malloc (sizeof(struct charIn *)*numProbs+1); // numProbs+1 for the NULL
	// sooo if bigInt.txt line 1 contains a 3, we make 3 structs that has two char * members
	// each char * member will keep receiving values
	//		first member will read up to a whitespace
	//		second member will read up to a newline

	int i = 0 ; 
	char ch ; 

	getc(file ); 
	// for the number of lines read in is less than the number of lines of probs
	for ( i = 0 ; (i < numProbs)  ; i++ ){
		// reset the count, buffer1, buffer2 for iteration i > 0 
		count = 0 ; // subscript + always (count < buffer-1) or relocate
		buffer1 = 30 ; // upperBound memory
		
		// malloc a struct *
		pointToPoint[i] = malloc(sizeof(struct charIn));
		// malloc a char 
		pointToPoint[i]->aProb1 = (char * )malloc(sizeof(char)*buffer1);
		pointToPoint[i]->aProb2 = (char * )malloc(sizeof(char)*buffer1);

		
		// while the read character is not an whitespace (32) or not end of file.
		while ( ch != 32 || !feof(file)){
			ch = getc(file);
			
			if ( count == buffer1-1){
				buffer1*=2 ; 
				pointToPoint[i]->aProb1 = (char *)realloc(pointToPoint[i]->aProb1,sizeof(char)*buffer1); 
			}else{
				
				// but if it is a white space, instead of the whitespace replace with a '\0', then break out of here
				if (ch == 32){
					pointToPoint[i]->aProb1[count] = '\0';
					// increment count so it now represents the number of elements + null, instead of a subscript 
					break ; 
				}else{
					pointToPoint[i]->aProb1[count] = ch ; 
				}
				count ++ ; 
			}
		}
	
		// log the count
		// count is the number of elements not the index
		pointToPoint[i]->size1 = count;  

		// reset the count 
		count = 0 ; 
		// reset the buffer 
		buffer1 = 30 ; 
		// reset holding variable ch
		ch = '\0';
		


		// found the whitespace? replace it with a null 
		// while second number to multiply is not a newline
		while (ch != 10 || !feof(file)){
			// read a char 
			ch = getc(file);
		
			// make sure that count < buffer2
			// if count is one less than the max size, then double the buffer size and reallocate
			if ( count == buffer1-1){
				buffer1*=2 ; 
				pointToPoint[i]->aProb2 = (char *)realloc(pointToPoint[i]->aProb2,sizeof(char)*buffer1); 
			}	
			
			// but if it is a newLine, instead of the newline replace with a '\0', then break out of here
			if (ch == 10 ){
				pointToPoint[i]->aProb2[count] = '\0';
				break ; 
			}else{
				pointToPoint[i]->aProb2[count] = ch ; 
				count++ ; 
				continue ; 
			}
			
		}
		// log the count
		pointToPoint[i]->size2 = count;  
		
		
		// lets shrink the size of these two sets of probs to the real size
		//pointToPoint[i]->aProb1 = (char *)realloc(pointToPoint[i]->aProb1,sizeof(char)*pointToPoint[i]->size1); 
		//pointToPoint[i]->aProb2 = (char *)realloc(pointToPoint[i]->aProb2,sizeof(char)*pointToPoint[i]->size2);
		/* DIAGNOSTICS */

	//printf("\n");
	//printChar(pointToPoint[i]->aProb1,pointToPoint[i]->size1);
	//printf("\n");		
	//printChar(pointToPoint[i]->aProb2,pointToPoint[i]->size2);
	//printInt(pointToPoint[i]->size1);
	//printInt(pointToPoint[i]->size2);
	}
	// Point the last index of pointToPoint (which doesn't contain anything) to NULL
	pointToPoint[i] = NULL ; 
	return pointToPoint ;
}
