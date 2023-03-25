#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct student
{   
    char a[100];      
    struct student *next;
};
void printnode(struct student *p)
{
    while(p!=NULL)
    {
      puts(p->a);
      p=p->next;
    }
}

void savetofile(struct student *p,char *filename)
{
    FILE *fp=fopen(filename,"w");
    if (fp==NULL){printf("file write error\n");return;}   
    while(p!=NULL)
    {
      fprintf(fp,"%s\n",p->a);
      p=p->next;
    }
    fclose(fp);
}

struct student *creatfromfile(char *filename)
{
      FILE *fp=fopen(filename,"r");
      if (fp==NULL)
      {
          printf("file read error\n"); 
          return NULL;
          } 
      struct student *head,*p1,*p2;      
      int n=0;    
      head=NULL;
      p1=( struct student *) malloc(sizeof(struct student));
      p2=p1;
      while(fscanf(fp,"%s",p1->a)!=EOF)
      {  
            n=n+1;	  
            if  (n==1) 
                  head=p1;  
            else   
                  p2->next=p1;
            p2=p1;	  
            p1=(struct student *)malloc(sizeof(struct student));
      }
      p2->next=NULL;      
      return(head);  
}

struct student *AddNewNodeEnd(struct student *head,struct student *newNode)
{
    struct student *p=head;
    if (head==NULL){
        head=newNode;
        newNode->next=NULL;
        return head;
    }
    while (p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;
    newNode->next=NULL;
    return head;
}

struct student *AddNewNodeFromKey(struct student *head)
{
    struct student *p;
    for (;;){
        p=( struct student *) malloc(sizeof(struct student));
        gets(p->a);
        if (strlen(p->a)!=0)
            head=AddNewNodeEnd(head,p);//head=AddNewNodeBegin(head,p);   
        else{
            free(p);
            break;
        }
    }
    return head;
}

void Rev_printNode(struct student *p){
  if (p==NULL) return;
  Rev_printNode(p->next);
  printf("%s\n", p->a );
}

void main()
{  
	struct student *head;
      printf("read old data:\n");
      head=creatfromfile("test1data.txt");
      printnode(head);
      
      //printf("\nRev-Print:\n");
      //Rev_printNode(head);

      //printf("creat new:\n");
      //head=creat();
      

      printf("\nAdd new node:\n");
      head=AddNewNodeFromKey(head);

      printf("\nDisplay All node:\n");
      printnode(head);
      savetofile(head,"test1data.txt");
}

