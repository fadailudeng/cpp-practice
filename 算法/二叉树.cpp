#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	char a;
	struct node *l;
	struct node *r;
}node;
int i=0;
node *start()
{
	char ch[]="ABDH#K###E##CFI###G#J##";
	node *p;
	if(ch[i]=='#')
	{
		i++;
		return NULL;
	}
	else
	{	
    	p=(node*)malloc(sizeof(node));
		p->a=ch[i++];
		p->l=start();
		p->r=start();
	}
	return p;
}
void print(node *q)
{
	if(q!=NULL)
	{
		printf("%c",q->a);
		print(q->l);
		print(q->r);
	}
}
main()
{
	node *p;
	p=start();
	print(p);
}