#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patients{
	char * name;
	char * organname ;
	struct patients * next ;
};
struct organGroups{
	char * organname ;
	struct patients * people;
	struct organGroups * next ;
}

struct organGroups * allocGroups(struct patients * person){
	struct organGroups * g = (struct organGroups *)malloc(sizeof(struct organGroups));
	g->next = g ;
	g->organname = (char *) malloc(sizeof(char)*strlen(person->organname));
	g->people = person ;
	return g ;
}
struct patients * insert(struct patients * people,struct patients * person){
	struct patients * p = people ;
	while ( p->next != NULL ){
		p=p->next ;
	}
	p->next = person ;
	return people ;
}
struct organGroups * insertPerson(struct organGroups * grps, struct patients * person ){
	struct organGroups * g = grps;

	while (g->next != grps ){
		if (strcmp(g->next.organname,person->organname)==0){
			g->next->people = insert(g->next->people,person);

		}
		g=g->next ;
	}
}