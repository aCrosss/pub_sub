#include <stdlib.h>
#include <string.h>
#include <zmq.h>
#include <assert.h>
#define BUFF_SIZE 256

int main(){
	void *context = zmq_ctx_new();
	void *socket = zmq_socket(context, ZMQ_PUB);
	if(zmq_bind(socket, "tcp://*:5555") != 0){
		printf("Failed to bind successfully\n");
		zmq_close(socket);
		zmq_ctx_destroy(context);
		return 1;
	}
	
	printf("Server listening port 5555\n");
	printf("Type send 'meesage' to send 'message' to the listener\n");
	printf("Type 'close' to stop publisher\n"); 
	
	while(1){
		printf("Enter command:\n");
		char *s = calloc(sizeof(char), BUFF_SIZE);
		fgets(s, BUFF_SIZE, stdin);
		s[strcspn(s, "\n")] = '\0';
		
		char *pcommand = s;
		char *pmessage = NULL;
		
		char *pspace = strchr(s, ' ');
		if (pspace != NULL){
			*pspace = '\0';
			pmessage = pspace + 1;
		}		
				
		if (strcmp(pcommand, "send") == 0){
			printf("Sending '%s'\n", pmessage);
			assert(zmq_send(socket, pmessage, strlen(pmessage), 0) > 0);
		} else if (strcmp(pcommand, "close") == 0){
			printf("Terminating\n");
			zmq_close(socket);
			zmq_ctx_destroy(context);
			free(s);
			return 0;
		} else{
			printf("Invalid command\n");
		}
	}
}
