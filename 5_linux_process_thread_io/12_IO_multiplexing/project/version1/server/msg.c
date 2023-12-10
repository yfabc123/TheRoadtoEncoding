#include "msg.h"

#define PATHNAME "../msg"
#define PRO_ID 102

#define MSG_SZ 64
struct msgbuf{
	long mtype;
	char mtext[MSG_SZ];
};
int msg_create()// 创建消息队列
{
	key_t key;
	int msgid;
	key = ftok(PATHNAME,PRO_ID);

	msgid = msgget(key,0);// 获取消息队列id
	if (msgid == -1){
		msgid = msgget(key,IPC_CREAT|0644);
		if (msgid == -1){
			perror("[ERROR] msgget(): ");
			return -1;
		}
	}

	return msgid;
}

int msg_send(int msgid,long mtype,char *buf)
{
	int ret;
	struct msgbuf msg;
	msg.mtype = mtype;
	strcpy(msg.mtext,buf);

	return msgsnd(msgid,(const void *)&msg,strlen(msg.mtext) + 1,0); 
}

int msg_recv(int msgid,long mtype,char *buf,int len)
{
	struct msgbuf msg;	
	int ret;

	ret = msgrcv(msgid,(void *)&msg,len,mtype,0);
	if (ret == -1){
		perror("[ERROR] msgrcv(): ");
		return -1;
	}

	strcpy(buf,msg.mtext);

	return ret;
}
int msg_del(int msgid)
{
	return msgctl(msgid,IPC_RMID,NULL);
}

