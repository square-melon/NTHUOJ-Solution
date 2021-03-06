#include <stdio.h>
#include "13133.h"
#define MAXN 100005
int arr[MAXN];
int main() {
	int N;
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d", &arr[i]);
	
	Node *head = NULL;
	createLinkedList(&head, N, arr);
	
	int Q;
	scanf("%d", &Q);
	for(int i=1;i<=Q;i++) {
		int a,b,len;
		scanf("%d %d %d", &a, &b, &len);
		swapTwoSegment(&head, a, b, len);
	}

	for(int i=1;i<=N;i++) {
		if(i > 1)	printf(" ");
		printf("%d", head->val);
		head = head->next;
	}
	printf("\n");
	return 0;
}
