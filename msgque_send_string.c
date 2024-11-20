#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

struct msgbuf
{
	long type;
	char data[512];
};

int main(int argc, char *argv[])
{
	struct msgbuf message;
	int msq_id;

	if(argc>=3)	
	{
		msq_id = atoi(argv[1]);
		
		message.type =atoi(argv[2]);
		strcpy(message.data, argv[3]);
		
		msgsnd(msq_id,&message, sizeof(message.data),0);
	}


	return 0;
}

