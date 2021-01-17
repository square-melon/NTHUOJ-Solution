#include "12350.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define ll long long int
#define next ptr_to_next_node
#define prev ptr_to_prev_node
#define ch character



int n, num;
char buf[10], intype;
Node *cursor;
extern Node *head, *tail;

void show()
{
	if(head == NULL){
		printf("\n");
		return;
	}
	Node *now = head->next;
	while(now != head)
	{
		printf("%c ", now->ch);
		now = now->next;
	}
	printf("\n");
}

int main()
{
	scanf("%d",&n);
	head = (Node*)malloc(sizeof(Node));
	head->next = head->prev = head;
	cursor = tail = head;
	while(n--)
	{
        
		scanf("%s",buf);
		if(!strcmp(buf,"insert"))
		{
			getchar();
			scanf("%c",&intype);
			insert(&cursor, intype); 
		}
		else if(!strcmp(buf,"deletion"))
		{
			deletion(&cursor); 
		}
		else if(!strcmp(buf,"backspace"))
		{
			backspace(&cursor); 
		}
		else if(!strcmp(buf,"go_left"))
		{
            scanf("%d", &num);
			go_left(&cursor, num); 
		}
        else if(!strcmp(buf,"go_right"))
		{
            scanf("%d", &num);
			go_right(&cursor, num); 
		}
        else if(!strcmp(buf,"go_home"))
		{
			go_home(&cursor); 
		}
        else if(!strcmp(buf,"go_end"))
		{
			go_end(&cursor); 
		}
		else if(!strcmp(buf,"show"))
		{
			show();
		}
	}
	return 0;
}



