#include<stdio.h>
#include<string.h>
#define MaxSize 255//Maximum number of characters in a word
#define n 100//the number of words
int function1(FILE* fp,char* string,int n1);//The first class meets the requirements of the word subscript query
int function2(FILE* fp,char* string,int n1);//The second class meets the requirements of the word subscript query
int function3(FILE* fp,char* string,int n1);//The third class meets the requirements of the word subscript query
int main()//Implement interface and file operation
{
	char filename[20];//the file name
	printf("***********************************************************\n");
	printf("**************************welcome**************************\n");
	printf("***********************************************************\n");
	//printf("please enter the filename:\n");
	//gets(filename);
	
	FILE *fp=fopen(  "dictionary.txt", "r" );//open the file
	FILE *fd=fopen(  "find.txt", "w" );//write the file
	if(fp==NULL||fd==NULL)
	{
		printf("file open unsuccessfully!\n");
		printf("please try again!\n");
		getchar();
		return 0;
	}
	else
	{
		printf("file open successfully!\n");
		char string[MaxSize];//we enter
		int count1=0;//The first case stores word subscripts
	   	int count2=0;//The second case stores word subscripts
		int count3=0;//The third case stores word subscripts
		printf("Please enter the word you need find:\n");
		scanf("%s",string);
		
		
	count1=function1(fp,string,n);
    count2=function2(fp,string,n);     
    count3=function3(fp,string,n);   
	printf("%d",count1) ;
	printf("\n");
	printf("%d",count2) ;
	printf("\n");
	printf("%d",count3) ;
	printf("\n");
	printf("file write successfully!");
   // fputs((char*)count1,n,fd);
    
	/*file write*/
	char ss1[5];
	ss1[0]='i';
	ss1[1]=' ';
	ss1[2]=count1+48;
	ss1[3]='\n';
	ss1[4]='\0';
	fputs(ss1,fd);
	
	char ss2[6];
	ss2[0]='E';
	ss2[1]='i';
	ss2[2]=' ';
	ss2[3]=count2+48;
	ss2[4]='\n';
	ss2[5]='\0';
	fputs(ss2,fd);
	
	char ss3[6];
	ss3[0]='F';
	ss3[1]='i';
	ss3[2]=' ';
	ss3[3]=count3+48;
	ss3[4]='\n';
	ss3[5]='\0';
	fputs(ss3,fd);
	
}
fclose(fp);
fclose(fd);
return 0;
}



int function1(FILE* fp,char* string,int n1)
{
	int i=1;
	int j=0;
	int length1=strlen(string);
	int length2=0;
	char temp1[MaxSize];
	while(i<=n1)
	{
		fgets(temp1,MaxSize,fp);//gets word from the file
		length2=strlen(temp1);//gets the length of the word
		//firstly we can compare the length of the word
		if(length1==length2-1)
		{
			while (temp1[j]!='\0')
			{
				if(temp1[j]!=string[j])
				{
					break;
				}
					j++;
				
			}
			
			if(j==length1)//all the character is correct!
			{
				return i;
			}
			
		}
		i++;
	}
	return 0;
	
}



int function2(FILE* fp,char* string,int n1)
{
	
	int i=1;
	int j=0;
	int count_not_same=0;
	int length1=strlen(string);
	int length2=0;
	char temp1[MaxSize];
	rewind(fp);
	while(i<=n1)
	{
		fgets(temp1,MaxSize,fp);//gets word from the file
		length2=strlen(temp1);//gets the length of the word
	//firstly we can compare the length of the word
		if(length1==length2-1)
		{
			while (temp1[j]!='\n')
			{
				if(temp1[j]!=string[j])
				{
					count_not_same++;
				}
					
					j++;
				
			}
			
			if(count_not_same==1)//only one character is not correct!
			{
				return i;
			}

        }
		i++;
}
return 0;
}

int function3(FILE* fp,char* string,int n1)
{
	int i=1;
	int j=0;
	int k=0;
	int length1=strlen(string);
	int length2=0;
	char temp1[MaxSize];
	char* a;
	rewind(fp);
	
	while(i<=n1)
	{
		fgets(temp1,MaxSize,fp);//gets word from the file
		length2=strlen(temp1);//gets the length of the word
	//firstly we can compare the length of the word
		if(length1==length2)//the word we enter is small than dic 1
			{
		
while (string[j]!='\0'){
			if(string[j]!=temp1[j])
			{
				break;
			}else{
				k++;
			}
			j++;
			}
		
				if(k==length2-1)
				{
					return i;
				}
			}
		
	
	
		if(length1==length2)//the word we enter is small than dic 1
		{
while (string[j]!='\n')
		{
			if(string[j+1]!=temp1[j])
			{
				break;
			}else{
				k++;
			}
			j++;
		}
		if(k==length2-1)
		{
			return i;
		}
		}
		
		
		
		else if(length1==length2-2)
		{
			a=strstr(temp1,string);
			if(a==temp1)
			{
				return i;
			}
		}
		
		i++;
}
return 0;
 }

