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
		printf("\n������ѧ����������");
		scanf("%d",&n);
		if(n<20)
			printf("����Ҫ����������20��\n");
	}while(n<20); 
	printf("\n�������ѧ����Ϣ����ʽ��ѧ�� ���� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� ������ɼ�\n");
	struct student * last;
	for(int i=0;i<n;i++)
	{
		struct student *data=(struct student*) malloc (sizeof(struct student));
		if(!data)
		{
			printf("�ڴ����ʧ�ܣ�");
			exit (0); 
		}
		scanf("%s %s %d %d %d %d",data->id,data->name,&data->chinese,&data->math,&data->english,&data->computer_science);
		if(i==0)
		{
			ptr->next=data;//ͷ���ָ���׽ڵ� 
			data->next=NULL;//�׽ڵ�ָ��� 
			last=data;//�׽ڵ�ָ�뱸�� 
		}
		else 
		{
			data->next=NULL;//�ýڵ�ָ��� 
			last->next=data;//�ϸ��ڵ�ָ��ýڵ� 
			last=data;//����ָ��Ϊ����ڵ� 
		}
	}
	printf("\n==============�����ѧ����Ϣ�ǣ�==============\n");
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
	printf("\n================ѧ��β��Ϊ09��ѧ����=================\n");
	if(ptr->next==NULL)
		printf("���󣺿ձ��޷�����ɼ���\n");
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
			printf("�鲻��������ѧ����\n");
	}
	printf("\n==================================================\n");
} 
 
void avg(struct student *ptr)
{
	printf("\n================ѧ��ƽ���ɼ��ǣ�=================\n");
	if(ptr->next==NULL)
		printf("���󣺿ձ��޷�����ɼ���");
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
		printf("���󣺿ձ��޷��޸ĳɼ���\n");
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
					printf("������Ҫ�޸�ѧ������Ϣ����ʽ��ѧ�� ���� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� ������ɼ�\n"); 
					scanf("%s %s %d %d %d %d",p->id,p->name,&p->chinese,&p->math,&p->english,&p->computer_science);
					printf("�޸ĺ���ϢΪ\n");
					printf("\n%s %s %d %d %d %d\n",p->id,p->name,p->chinese,p->math,p->english,p->computer_science);
				}
			}
			if(p->next!=NULL)
				p=p->next;
			else 
				break;
		}
		if(flag==0)
			printf("�鲻��������ѧ�����޷��޸ģ�\n");
	}
	printf("\n==================================================\n");
}

void taxis(struct student *ptr)
{
	if(ptr->next==NULL)
		printf("���󣺿ձ��޷���ѯ�ɼ���\n");
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
	printf("============��ӭʹ��ѧ���ɼ�����ϵͳ============\n"); 
	struct student *ptr=(struct student*) malloc (sizeof(struct student));
	if(!ptr)
	{
		printf("�ڴ����ʧ�ܣ�");
		exit (0); 
	}
	ptr->next=NULL;
	while(1)
	{
		printf("=================================================\n");
		printf("1.¼��ɼ�\n");
		printf("2.��ѯ�ɼ�\n");
		printf("3.�޸ĳɼ�\n");
		printf("4.����ɼ�\n"); 
		printf("5.ͳ�Ƴɼ�\n");
		printf("0.�˳�����\n");
		printf("���������ѡ��\n");
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
				struct student *t=p->next;//�����¸��ڵ��ַ 
				free(p);//�ͷŵ�ǰ��� 
				p=t;//��Ϊ�¸��ڵ� 
				if(t==NULL)
					break;
			}
			exit (0); 
		}
		else 
		{ 
			printf("\n������������ԣ�\n");
			printf("=================================================\n");
		} 
	}
	return 0;
}
