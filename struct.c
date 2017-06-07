#include <stdio.h>
#include <conio.h> 
#include <windows.h>
#include <string.h>

struct student
{
	char id[20];
	char name[20];
	int chinese;
	int math;
	int english;
	int computer_science;
	struct student *next;
};

void insert(struct student *ptr)
{
	int n;
	do
	{
		printf("\n请输入学生的人数：");
		scanf("%d",&n);
		if(n<20)
			printf("程序要求至少输入20人\n");
	}while(n<20); 
	printf("\n请输入该学生信息，格式：学号 名字 语文成绩 数学成绩 英语成绩 计算机成绩\n");
	struct student * last;
	for(int i=0;i<n;i++)
	{
		struct student *data=(struct student*) malloc (sizeof(struct student));
		if(!data)
		{
			printf("内存分配失败！");
			exit (0); 
		}
		scanf("%s %s %d %d %d %d",data->id,data->name,&data->chinese,&data->math,&data->english,&data->computer_science);
		if(i==0)
		{
			ptr->next=data;//头结点指向首节点 
			data->next=NULL;//首节点指向空 
			last=data;//首节点指针备份 
		}
		else 
		{
			data->next=NULL;//该节点指向空 
			last->next=data;//上个节点指向该节点 
			last=data;//更新指针为这个节点 
		}
	}
	printf("\n==============你输的学生信息是：==============\n");
	for(struct student *p=ptr->next;;)
	{
		printf("\n%s %s %d %d %d %d\n",p->id,p->name,p->chinese,p->math,p->english,p->computer_science);
		if(p->next!=NULL)
			p=p->next;
		else 
			break;
	}
}

void search(struct student *ptr)
{
	printf("\n================学号尾号为09的学生是=================\n");
	if(ptr->next==NULL)
		printf("错误：空表无法输出成绩！\n");
	else
	{
		int flag=0;
		for(struct student *p=ptr->next;;)
		{
			char *temp=p->id;
			if(strlen(temp)>=2)
			{
				while(*(temp+2)!='\0')
					temp++;
				if((*temp=='0')&&(*(temp+1)=='9'))
				{
					flag=1;
					printf("\n%s %s %d %d %d %d\n",p->id,p->name,p->chinese,p->math,p->english,p->computer_science);
				}
			}
			if(p->next!=NULL)
				p=p->next;
			else 
				break;
		}
		if(flag==0)
			printf("查不到这样的学生！\n");
	}
	printf("\n==================================================\n");
} 
 
void avg(struct student *ptr)
{
	printf("\n================学生平均成绩是：=================\n");
	if(ptr->next==NULL)
		printf("错误：空表无法输出成绩！");
	else
	{
		for(struct student *p=ptr->next;;)
		{
			double sum=((p->chinese)+(p->math)+(p->english)+(p->computer_science))/4;
			printf("\n%s %s %.2lf\n",p->id,p->name,sum);
			if(p->next!=NULL)
				p=p->next;
			else 
				break;
		}
	}
	printf("\n==================================================\n");
} 

void edit(struct student *ptr)
{
	if(ptr->next==NULL)
		printf("错误：空表无法修改成绩！\n");
	else
	{
		int flag=0;
		for(struct student *p=ptr->next;;)
		{
			char *temp=p->id;
			if(strlen(temp)>=2)
			{
				while(*(temp+2)!='\0')
					temp++;
				if((*temp=='1')&&(*(temp+1)=='2'))
				{
					flag=1;
					printf("请输入要修改学生的信息，格式：学号 名字 语文成绩 数学成绩 英语成绩 计算机成绩\n"); 
					scanf("%s %s %d %d %d %d",p->id,p->name,&p->chinese,&p->math,&p->english,&p->computer_science);
					printf("修改后信息为\n");
					printf("\n%s %s %d %d %d %d\n",p->id,p->name,p->chinese,p->math,p->english,p->computer_science);
				}
			}
			if(p->next!=NULL)
				p=p->next;
			else 
				break;
		}
		if(flag==0)
			printf("查不到这样的学生，无法修改！\n");
	}
	printf("\n==================================================\n");
}

void taxis(struct student *ptr)
{
	if(ptr->next==NULL)
		printf("错误：空表无法查询成绩！\n");
	else
	{
		for(struct student *p=ptr->next;;)
		{ 
			for(struct student *t=p->next;;)
			{
				if((t->chinese)>(p->chinese))
				{
					char tid[20];
					strcpy(tid,p->id);
					char tname[20];
					strcpy(tname,p->name);
					int tchinese=p->chinese;
					int tmath=p->math;
					int tenglish=p->english;
					int tcomputer_science=p->computer_science;
					strcpy(p->id,t->id);
					strcpy(p->name,t->name);
					p->chinese=t->chinese;
					p->math=t->math;
					p->english=t->english;
					p->computer_science=t->computer_science;
					strcpy(t->id,tid);
					strcpy(t->name,tname);
					t->chinese=tchinese;
					t->english=tenglish;
					t->math=tmath;
					t->computer_science=tcomputer_science;
				}
				if(t->next!=NULL)
					t=t->next;
				else 
					break;
			}
			if(p->next->next!=NULL)
				p=p->next;
			else 
				break;
		}
		for(struct student *p=ptr->next;;)
		{
			printf("\n%s %s %d %d %d %d\n",p->id,p->name,p->chinese,p->math,p->english,p->computer_science);
			if(p->next!=NULL)
				p=p->next;
			else 
				break;
		}
	} 
	printf("\n==================================================\n");
}

int main(void)
{
	printf("============欢迎使用学生成绩管理系统============\n"); 
	struct student *ptr=(struct student*) malloc (sizeof(struct student));
	if(!ptr)
	{
		printf("内存分配失败！");
		exit (0); 
	}
	ptr->next=NULL;
	while(1)
	{
		printf("=================================================\n");
		printf("1.录入成绩\n");
		printf("2.查询成绩\n");
		printf("3.修改成绩\n");
		printf("4.排序成绩\n"); 
		printf("5.统计成绩\n");
		printf("0.退出程序\n");
		printf("请输入你的选择：\n");
		printf("=================================================\n");
		fflush(stdin);
		char ch=getch();
		if(ch=='1')
			insert(ptr); 
		else if(ch=='2')
			search(ptr);
		else if(ch=='3')
			edit(ptr); 
		else if(ch=='4')
			taxis(ptr);
		else if(ch=='5')
			avg(ptr);
		else if(ch=='0')
		{
			
			for(struct student *p=ptr;;)
			{
				struct student *t=p->next;//备份下个节点地址 
				free(p);//释放当前结点 
				p=t;//变为下个节点 
				if(t==NULL)
					break;
			}
			exit (0); 
		}
		else 
		{ 
			printf("\n输入错误请重试！\n");
			printf("=================================================\n");
		} 
	}
	return 0;
}
