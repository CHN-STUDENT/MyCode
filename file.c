#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
void merge(void)
{//�ϲ��ļ����� 
	FILE *s; 
	printf("\n������ϲ��ļ���·����ַ��\n");
	char save[256];
	printf("\n"); 
	gets(save);
	printf("\n"); 
	s=fopen(save,"wb"); 
	if(!s)
	{
		printf("\n�޷�����ļ��������ԣ�\n");
		exit -1; 
	} 
	printf("\n----------------------------\n");
	printf("\n           ��ע             \n");
	printf("\n �����������ǰĿ¼��*.part \n");
	printf("\n    ���һ��Զ��ϳ�����    \n");
	printf("\n----------------------------\n");
	int nemb=0;
	char name[100]; 
	char ch;
	for(;;nemb++)
	{
		_itoa(nemb,name,10);//������ת�����ַ�����������aת��10�����ַ�������name�� 
		// _itoa(int num,char *ch,int radix)  
		strcat(name,".part");
		FILE *open=fopen(name,"rb");
		if(!open)  
		{//����*.part,����򲻿�����Ϊ���� 
			fclose(s);
			break;
		}
		while(1)
		{
			fread(&ch,sizeof(char),1,open);//��������f(�ļ�ָ��)ÿ�ζ�ȡһ��������(�ַ�char),һ��������8���ֽڣ����ڽ�������ch�ڴ��ַ��
			if(feof(open)!=0)
				break; 
			fwrite(&ch,sizeof(char),1,s);
		}
		fclose(open);
	}	
	printf("\n�ϲ������Ѿ���ɣ�\n"); 
}; 

void compare(void)
{//�Ƚ��ļ�����
	FILE *f1;
	while(1)
	{
		printf("\n������Ƚ�Դ�ļ�·����ַ��\n");
		char filepath1[256];
		printf("\n"); 
		gets(filepath1);
		printf("\n"); 
		f1=fopen(filepath1,"rb"); 
		if(!f1)
		{
			printf("\n�ļ���ʧ�ܣ������ԣ�\n"); 
			printf("\n----------------------------\n"); 
		} 
		if(f1)
			break;
	} 
	FILE *f2;
	while(1)
	{
		printf("\n������ȽϺϲ��ļ�·����ַ��\n");
		char filepath2[256];
		printf("\n"); 
		gets(filepath2);
		printf("\n"); 
		f2=fopen(filepath2,"rb"); 
		if(!f2)
		{
			printf("\n�ļ���ʧ�ܣ������ԣ�\n"); 
			printf("\n----------------------------\n"); 
		} 
		if(f2)
			break;
	}
	long data1=0;
	long data2=0;
	while(feof(f1)!=0)
	{
		data1++;
	}
	while(feof(f2)!=0)
	{
		data2++;
	}
	if(data1!=data2)
	{
		printf("\n----------------------------\n"); 
		printf("\n�ļ�У��ʧ�ܣ�\n");
		
	} 
	else
	{ 
		char ch1;
		char ch2;
		int sign=0;
		while(1)
		{
			fread(&ch1,sizeof(char),1,f1);
			fread(&ch2,sizeof(char),1,f2);
			if(ch1!=ch2)
			{
				sign=1;
				printf("\n----------------------------\n"); 
				printf("\n�ļ�У��ʧ�ܣ�\n");
				break;	
			}
			if(feof(f2)!=0&&feof(f2)!=0)
				break; 
		}
		if(sign==0)
		{
			printf("\n----------------------------\n"); 
			printf("\n�ļ�У��ɹ���\n");
		}	
	}
};

void split(void)
{//�ָ��ļ����� 
	FILE *f;
	while(1)
	{ 
		printf("\n������ָ��ļ�·����ַ:\n");
		char filepath[256];
		printf("\n"); 
		gets(filepath);
		printf("\n"); 
		f=fopen(filepath,"rb"); 
		if(!f)
		{
			printf("\n�ļ���ʧ�ܣ������ԣ�\n"); 
			printf("\n----------------------------\n"); 
		} 
		if(f)
			break;
	} 
	printf("\n----------------------------\n");
	printf("\n           ��ע             \n");
	printf("\n �ָ���ļ�����Ϊ*.part��ʽ \n");
	printf("\n----------------------------\n");
	printf("\n������ÿ�ݵĴ�С(��λByte):\n");
	int data;
	char temp[1048576];
	printf("\n");
	scanf("%d",&data);	
	int b=1;//bΪ1byte 
	int nemb=0;//nemb�ļ��� 
	char name[100];
	int stopAll=0;
	char ch;
	for(;;nemb++)
	{
		_itoa(nemb,name,10);//������ת�����ַ�����������aת��10�����ַ�������name�� 
		// _itoa(int num,char *ch,int radix)  
		strcat(name,".part");
		FILE *out=fopen(name,"wb");
		if(!out)
		{
			printf("��ȡ�ļ�����");
			exit -1;
		}
		for(int b=1;b<=data;b++)
		{
			fread(&ch,sizeof(char),1,f);//��������f(�ļ�ָ��)ÿ�ζ�ȡһ��������(�ַ�char),һ��������8���ֽڣ����ڽ�������ch�ڴ��ַ�� 
			//fread ( void *buffer, size_t size, size_t count, FILE *stream); 
			if(feof(f))
			{//��������ļ�ĩβ 
				stopAll=1;  //״̬����=1 
				break;  
			}
			fwrite(&ch,sizeof(char),1,out);
		}//for(int b=1;b<=size;b++)
		fclose(out);//�ļ�ָ��ر�
		if(stopAll!=0)
			break;
	}
	fclose(f); 
	printf("\n----------------------------\n");
	printf("\n�ָ�����Ѿ���ɣ�\n"); 
};
 
int main(int argc ,char ** argv)
{
	
	system("mode con cols=28");//���ÿ��28
	system("color A");//��������Ϊ��ɫ 
	printf("\n----------------------------\n"); 
	printf("\n------�ļ��ָ���ϲ���------\n");
	printf("\n------      V0.0.1    ------\n"); 
	char input; 
	while(1)
	{
		fflush(stdin);//����ӣ���Ȼ�ڶ���ִ�л��bug�� 
		printf("\n----------------------------\n"); 
		printf("\n�����룺\n"); 
		printf("\n1.�ָ�\n");
		printf("\n2.�ϲ�\n");
		printf("\n3.У���ļ�\n"); 
		printf("\ne.�˳�\n"); 
		printf("\n----------------------------\n"); 
		input=getch();
		if(input!='1'&&input!='2'&&input!='3'&&input!='e')
			printf("\n�������������\n");
		if(input=='1')
			split(); 
		if(input=='2')
			merge(); 
		if(input=='3') 
			compare(); 
		if(input=='e') 
			exit (0);
	} 
	return 0;
}
