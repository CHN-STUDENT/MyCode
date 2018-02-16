#include<stdio.h>
main()
{
	FILE *fp;
	int num2,k,d,a;
	int numa;
	char chara,c;
	char ch[1024];
	if ((fp=fopen ("FONT.BIN","rb"))==NULL)
	{
		printf("File open fail");
	}
	for(int num1=0;num1<=1024;num1++)
	{
		ch[num1]=fgetc(fp);
	}
	fclose(fp);
	for(;;)
	{
		printf("ÇëÊäÈëÒ»¸ö×Ö·û:");
		scanf("%c",&chara);
		fflush(stdin);
		a=chara*8;
		for(k=0;k<8;k++)
		{
			c=ch[a+k];
			for(d=0;d<8;d++)
			{
				if((c&0x80)==0)
					printf(" ");
				else
					printf("*");
				c<<=1;
			}
			printf("\n");
		}
	}
}
