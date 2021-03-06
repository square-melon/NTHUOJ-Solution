typedef struct node {
	struct node* next;
	int val;
} Node;

void createLinkedList(Node **head, int N, int *arr) {
	Node* cur = *head;
	*head = (Node*)malloc(sizeof(Node));
	(*head)->val = arr[0];
	for (int i = 1; i < N; i++) {
		cur = cur->next = (Node*)malloc(sizeof(Node));
		cur->val = arr[i];
	}
	cur->next = *head;
}

void swapTwoSegment(Node **head, int a, int b, int len) {
	Node *cura = *head, *curb = *head, *curas, *curbs, *prea = NULL, *preb = NULL;
	a--, b--;
	int len2 = len-1;
	while (a--) {
		prea = cura;
		cura = cura->next;
	}
	curas = cura;
	while (len2--) cura = cura->next;
	while (b--) {
		preb = curb;
		curb = curb->next;
	}
	curbs = curb;
	len2 = len-1;
	while (len2--) curb = curb->next;
	if (!prea) {
		prea = *head;
		while (prea->next != head) prea = prea->next;
	}
	if (!preb) {
		preb = *head;
		while(preb->next != head) preb = preb->next;
	}
}
