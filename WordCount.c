#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

struct symbol
{
 char name[20];
 int count;
};

struct symbol table[375000];


void insertion_sort(struct symbol *lp,int count){
int i,j;
char *temp;
int eee;

for(i=1;i<count;i++){
	strcpy(temp,(lp+i)->name);
	eee=(lp+i)->count;

for(j=i-1;j>=0&&(strcmp((lp+j)->name,temp)>0);j--){
	strcpy((lp+j+1)->name,(lp+j)->name);
	(lp+j+1)->count=(lp+j)->count;
	}
	strcpy((lp+j+1)->name,temp);
	(lp+j+1)->count=eee;
	}
}

void heap_sort(struct symbol *lp,int count){
	int eee;
	char *temp;
	 for(int i=1; i<count;i++){
	 int c=i;
	
	 do{
	int root=(c-1)/2;

	if(strcmp((lp+root)->name,(lp+c)->name)<0){
	strcpy(temp,(lp+root)->name);
	strcpy((lp+root)->name,(lp+c)->name);
	strcpy((lp+c)->name,temp);
	
	eee=(lp+root)->count;
	(lp+root)->count=(lp+c)->count;
	(lp+c)->count=eee;
	}
	c=root;
	}while(c!=0);
	}

for(int i=count-1;i>=0;i--){
	strcpy(temp,(lp+0)->name);
        strcpy((lp+0)->name,(lp+i)->name);
	strcpy((lp+i)->name,temp);
	
	eee=(lp+0)->count;
	(lp+0)->count=(lp+i)->count;
	(lp+i)->count=eee;
	
	int root=0;
	int c=1;
		
	do{
	c=2*root+1;

	if((c<i-1)&&strcmp((lp+c)->name,(lp+c+1)->name)<0){
		c++;
		
	}
	if(c<i&&strcmp((lp+root)->name,(lp+c)->name)<0){
	strcpy(temp,(lp+root)->name);
	strcpy((lp+root)->name,(lp+c)->name);
	strcpy((lp+c)->name,temp);
	
	eee=(lp+root)->count;
	(lp+root)->count=(lp+c)->count;
	(lp+c)->count=eee;
	}
	root=c;
	}while(c<i);
	}	
}

void shell_sort(struct symbol *lp,int n){

 int i,j,s,eee,count;
    count=n;
    char *temp;

 while(count > 1)
    {
        count = count / 2;

        for(s=0; s < count; s++)
        {
            for(i=s; i < n; i+=count)
            {
                eee=(lp+i)->count;
		strcpy(temp,(lp+i)->name);
                j=i-count;
                while(j >= 0 && (lp+j)->count < eee)
                {
                    (lp+j+count)->count=(lp+j)->count;
		    strcpy((lp+j+count)->name,(lp+j)->name);
                    j-=count;
                }
               (lp+j+count)->count=eee;
	       strcpy((lp+j+count)->name,temp);
            }
        }
    }
}

int main(int argc,char *argv[]){

char *token;
 char s[376000];
 char seps[] = " ,\t\n";
 int i, j;
 int ch;
 extern char *optarg;

    for(i=0;i<375493;i++){
         fflush(stdin);
         s[i]=getchar();
       }

token = strtok(s, seps);
for(i = 0, j = 0; token != NULL; )
 {
 for(i = 0; i < j; i++)
  {
 if(strcmp(table[i].name, token) == 0) 
  {
   table[i].count++;
    break;
   }
  }
  if(i == j) 

  {
   strcpy(table[j].name, token); 
   table[j].count = 1; 
   j++;
  }
  token = strtok(NULL, seps);
 }


 while ((ch = getopt(argc, argv, "abc:")) != -1) {  
	
	 switch (ch) { 

            case 'a':
                insertion_sort(table,j);
		for(i = 0; i < j; i++)
 		printf("%s %d\n",table[i].name, table[i].count);

               break;

            case 'b': 
                shell_sort(table,j);
		 for(i = 0; i < j; i++)
                 printf("%s %d\n",table[i].name, table[i].count);

                break;
		

             case 'c':
		for(i=0;i<j;i++){
			if(strcmp(table[i].name,optarg)==0){
			break;
				}
               heap_sort(table,j);
			}
		printf("%s %d\n",table[i].name,table[i].count);
                break;
	 }
 }
 return 0;
}

