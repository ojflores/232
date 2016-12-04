#define MAX_BUFFER 99

typedef struct node{
	int val;
	struct node * next;
}node_t;

void push(node_t * head, int value){
	node_t * current = head;
	
	while (current->next != NULL){
		current = current->next;
	}
	current->next = malloc(sizeof(node_t));
	current->next->val = value;
	current->next->next = NULL;
	return;
}

void parse_exec() {
	char line[MAX_BUFFER]; 
	fgets(line, MAX_BUFFER, stdin);
	int vertex_count = atoi(line);
	node_t * array[vertex_count];
	int i;
	for (i = 0; i < vertex_count; i++){
		const char space[2] = " ";
		char * token;
		if (fgets(line, MAX_BUFFER, stdin) != NULL){
			token = strtok(line, space);
			while(token != NULL){
				// insert integer version of token into appropriate linked list
				int number = atoi(token);
				push(array[i], number);
				token = strtok(NULL, space);
			}
		}
		
	}
	
}