#include <stdio.h>
#include <sys/msg.h>

struct msgbuf
{
	long type;
	char data[512];
};


int main(void)
{

	struct msgbuf message;

	int msq_id;
	
	msq_id = msgget(IPC_PRIVATE, IPC_CREAT|0666);

	printf("message id is %d\n",msq_id);
	while(1)
	{
		msgrcv(msq_id, &message, sizeof(message.data), 0,0);
		printf("message(id=%d) is %s\n",msq_id,message.data);
	}

	return 0;
}