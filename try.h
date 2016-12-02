#define MAX_BUFFER 99

typedef struct node{
	int val;
	struct node * next;
}node_t;

void parse_exec() {
	char line[MAX_BUFFER]; 
	fgets(line, MAX_BUFFER, stdin);
	int vertex_count = atoi(line);
	node_t * array[vertex_count];
	int i;
	for (i = 0; i < vertex_count; i++){
		const char space[2] = " "
		char *token;
		if (fgets(line, MAX_BUFFER, stdin) != NULL){
			token = strtok(line, space);
			while(token != NULL){
				// insert integer version of token into appropriate linked list
				
				token = strtok(NULL, space);
			}
		}
		
	}
	while( fgets(line, MAX_BUFFER, stdin) != NULL ) { 
		parsed_line = parse_line(line);
	}
}