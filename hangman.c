#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void draw_hangman(int p)
{	char *hangman[6];
	int i;
	for(i=0;i<6;i++)
		hangman[i]=(char*)malloc(sizeof(char)*50);
	hangman[0]="\n\t|========|\n\t|\t\\O/\n\t|\t |\n\t|\t/ \\\n\t|\n\t|";		//
	hangman[1]="\n\t|========|\n\t|\t\\O/\n\t|\t |\n\t|\t/   \n\t|\n\t|";		//
	hangman[2]="\n\t|========|\n\t|\t\\O/\n\t|\t |\n\t|\t    \n\t|\n\t|";		//
	hangman[3]="\n\t|========|\n\t|\t\\O/\n\t|\t  \n\t|\t    \n\t|\n\t|";		//
	hangman[4]="\n\t|========|\n\t|\t\\O \n\t|\t  \n\t|\t    \n\t|\n\t|";		//
	hangman[5]="\n\t|========|\n\t|\t O \n\t|\t  \n\t|\t    \n\t|\n\t|";		//
	printf("%s\n",hangman[p]);
}
int main()
{	int i,n,l,k,lives=6,w,f;
	char s[][15]={"ELEPHANT","CROCODILE","RHINOCEROS","HIPPOPOTAMUS","KANGAROO"};
	n=5;
	srand(time(NULL));
	w=random()%n;
	l=k=strlen(s[w]);
	char a[l],c;
	for(i=0;i<l;i++)
	{	a[i]='_';
		printf("%c ",a[i]);
	}
	while(lives>0 && k>0)
	{	f=0;
		printf("\n\nEnter the letter : ");
		scanf("%c",&c);
		getchar();
		for(i=0;s[w][i]!='\0';i++)
		{	if(s[w][i]==c && a[i]=='_')
			{	a[i]=c;
				k--;
				f=1;
			}
		}
		if(f==0)
		{	lives--;
			draw_hangman(lives);
			if(lives==0)
			{	printf("\nGAME OVER\n\n");
				break;
			}
		}
		printf("\n");
		for(i=0;i<l;i++)
			printf("%c ",a[i]);
		
	}
	if(lives!=0)
		printf("\n\nCONGRATS\n");		
	return 0;
}
