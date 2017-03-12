#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
void merge(void)
{//合并文件函数 
	FILE *s; 
	printf("\n请输入合并文件的路径地址：\n");
	char save[256];
	printf("\n"); 
	gets(save);
	printf("\n"); 
	s=fopen(save,"wb"); 
	if(!s)
	{
		printf("\n无法另存文件，请重试！\n");
		exit -1; 
	} 
	printf("\n----------------------------\n");
	printf("\n           备注             \n");
	printf("\n 程序会搜索当前目录下*.part \n");
	printf("\n    并且会自动合成它们    \n");
	printf("\n----------------------------\n");
	int nemb=0;
	char name[100]; 
	char ch;
	for(;;nemb++)
	{
		_itoa(nemb,name,10);//将数字转换成字符串，将数字a转成10进制字符串存在name里 
		// _itoa(int num,char *ch,int radix)  
		strcat(name,".part");
		FILE *open=fopen(name,"rb");
		if(!open)  
		{//遍历*.part,如果打不开则认为结束 
			fclose(s);
			break;
		}
		while(1)
		{
			fread(&ch,sizeof(char),1,open);//从输入流f(文件指针)每次读取一个数据项(字符char),一个数据项8个字节，存在接受数据ch内存地址中
			if(feof(open)!=0)
				break; 
			fwrite(&ch,sizeof(char),1,s);
		}
		fclose(open);
	}	
	printf("\n合并操作已经完成！\n"); 
}; 

void compare(void)
{//比较文件函数
	FILE *f1;
	while(1)
	{
		printf("\n请输入比较源文件路径地址：\n");
		char filepath1[256];
		printf("\n"); 
		gets(filepath1);
		printf("\n"); 
		f1=fopen(filepath1,"rb"); 
		if(!f1)
		{
			printf("\n文件打开失败，请重试！\n"); 
			printf("\n----------------------------\n"); 
		} 
		if(f1)
			break;
	} 
	FILE *f2;
	while(1)
	{
		printf("\n请输入比较合并文件路径地址：\n");
		char filepath2[256];
		printf("\n"); 
		gets(filepath2);
		printf("\n"); 
		f2=fopen(filepath2,"rb"); 
		if(!f2)
		{
			printf("\n文件打开失败，请重试！\n"); 
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
		printf("\n文件校验失败！\n");
		
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
				printf("\n文件校验失败！\n");
				break;	
			}
			if(feof(f2)!=0&&feof(f2)!=0)
				break; 
		}
		if(sign==0)
		{
			printf("\n----------------------------\n"); 
			printf("\n文件校验成功！\n");
		}	
	}
};

void split(void)
{//分割文件函数 
	FILE *f;
	while(1)
	{ 
		printf("\n请输入分割文件路径地址:\n");
		char filepath[256];
		printf("\n"); 
		gets(filepath);
		printf("\n"); 
		f=fopen(filepath,"rb"); 
		if(!f)
		{
			printf("\n文件打开失败，请重试！\n"); 
			printf("\n----------------------------\n"); 
		} 
		if(f)
			break;
	} 
	printf("\n----------------------------\n");
	printf("\n           备注             \n");
	printf("\n 分割的文件将存为*.part格式 \n");
	printf("\n----------------------------\n");
	printf("\n请输入每份的大小(单位Byte):\n");
	int data;
	char temp[1048576];
	printf("\n");
	scanf("%d",&data);	
	int b=1;//b为1byte 
	int nemb=0;//nemb文件名 
	char name[100];
	int stopAll=0;
	char ch;
	for(;;nemb++)
	{
		_itoa(nemb,name,10);//将数字转换成字符串，将数字a转成10进制字符串存在name里 
		// _itoa(int num,char *ch,int radix)  
		strcat(name,".part");
		FILE *out=fopen(name,"wb");
		if(!out)
		{
			printf("存取文件错误");
			exit -1;
		}
		for(int b=1;b<=data;b++)
		{
			fread(&ch,sizeof(char),1,f);//从输入流f(文件指针)每次读取一个数据项(字符char),一个数据项8个字节，存在接受数据ch内存地址中 
			//fread ( void *buffer, size_t size, size_t count, FILE *stream); 
			if(feof(f))
			{//如果读到文件末尾 
				stopAll=1;  //状态函数=1 
				break;  
			}
			fwrite(&ch,sizeof(char),1,out);
		}//for(int b=1;b<=size;b++)
		fclose(out);//文件指针关闭
		if(stopAll!=0)
			break;
	}
	fclose(f); 
	printf("\n----------------------------\n");
	printf("\n分割操作已经完成！\n"); 
};
 
int main(int argc ,char ** argv)
{
	
	system("mode con cols=28");//设置宽度28
	system("color A");//字体设置为绿色 
	printf("\n----------------------------\n"); 
	printf("\n------文件分割与合并器------\n");
	printf("\n------      V0.0.1    ------\n"); 
	char input; 
	while(1)
	{
		fflush(stdin);//必须加！不然第二次执行会出bug。 
		printf("\n----------------------------\n"); 
		printf("\n请输入：\n"); 
		printf("\n1.分割\n");
		printf("\n2.合并\n");
		printf("\n3.校验文件\n"); 
		printf("\ne.退出\n"); 
		printf("\n----------------------------\n"); 
		input=getch();
		if(input!='1'&&input!='2'&&input!='3'&&input!='e')
			printf("\n输入错误，请重试\n");
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
