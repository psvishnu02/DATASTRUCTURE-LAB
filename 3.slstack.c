#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node * sp = (struct node*)0;

void push(int item)
{
struct node * t;
t=(struct node *)malloc(sizeof(struct node*));
t->data=item;
t->next=sp;
sp=t;
return;
}
//delete an item from stack
int pop()
{
struct node * t;
int item;
if(sp==(struct node*)0)
printf("empty stack");
else
{
item= sp->data;
t=sp;
sp=sp->next;
free(t);
return item;
}
}

//search an item in stack
int search (int item)
{
struct node * t=sp;
int count=0;
while(t!=(struct node*)0)
{++count;
if(t->data==item)
return count; //item forward
t=t->next;
}
return 0; //not found
}

void main()
{
int item,opt,ans;
do
{
printf("Options\n");
printf("1.push:\n");
printf("2.pop:\n");
printf("3.Search:\n");
printf("4.Exit:\n\n");
printf("Enter an option:\n");
scanf("%d", &opt);
switch(opt)
{
case 1:printf("data:\n");
       scanf("%d", &item);
       push (item);
       break;
case 2:item=pop();
       printf("deleted %d\n",item);
       break;
case 3:printf("no to search\n");
       scanf("%d", &item);
       ans=search(item);
       if(ans==0)
       printf("Item not found\n");
       else
       printf("found at %dth position\n", ans);
       break;
case 4:exit(0);
}
}
while(1);
}

