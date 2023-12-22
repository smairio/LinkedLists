#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

typedef int DATA;
typedef struct List{
	DATA data;
	struct List * next;
}List;

void printRecursive(List *);
void printMenu();
DATA scantarget();
DATA scanvalue();
List * addHead(List *,DATA);
List * addTail(List *,DATA);



// delete functions
List * deleteFirstNode(List *);
List * deleteList(List *);
List * deleteNode(List *,DATA);
List * deleteAllOccurencesOfNode(List *,DATA);
// delete functions


//insert after
void addAfterNode(List*,DATA);
void addAfterFirstOccurence(List *,DATA,DATA);
void addAfterEveryOccurence(List *,DATA,DATA);
//insert after

//insert before

void addBeforeNode(List*,DATA);
void addBeforeFirstOccurence(List *,DATA,DATA);
void addBeforeEveryOccurence(List *,DATA,DATA);
//insert before

int main(){
	List * head = NULL;
	head = addHead(head,4);
	head = addHead(head,5);
	head = addHead(head,5);
	head = addHead(head,4);
	head = addHead(head,5);
	head = addHead(head,5);
	addBeforeEveryOccurence(head,4,6);


	printRecursive(head);
	int choice;
	while(true){
		printMenu();
		scanf("%d",&choice);
		system("cls");
		switch(choice){
			case 1:
				head = addHead(head,scanvalue());
				break;

			case 2:
				head = addTail(head,scanvalue());
				break;

			case 3:
				addAfterFirstOccurence(head,scantarget(),scanvalue());
				break;

			case 4:
				addAfterEveryOccurence(head,scantarget(),scanvalue());
				break;

			case 5:
				addBeforeFirstOccurence(head,scantarget(),scanvalue());
				break;

			case 6:
				addBeforeEveryOccurence(head,scantarget(),scanvalue());
				break;

			case 7:
				head = deleteNode(head,scantarget());
				break;

			case 8:
				head = deleteAllOccurencesOfNode(head,scantarget());
				break;

			case 9:	
				head = deleteFirstNode(head);
				break;

			case 10:
				head = deleteList(head);
				break;

			case 11:
				printRecursive(head);
				break;
			case 12:
				head = deleteList(head);
				exit(0);

			default:
				printf("Wrong Option!\n");
				break;


		}
		printf("Press any key to Continue");
		getche();
		system("cls");
	}
	
	
	
	


	return 0;
}

List * addHead(List * head,DATA data){
	List * new = malloc(sizeof(List));
	if(!new){
		printf("Allocation error");
		exit(-1);
	}
	new->data=data;
	if(!head)
		new->next=NULL;
	else
		new->next=head;
	return new;
}

List * addTail(List * head,DATA data){
	
	List * new = malloc(sizeof(List));
	if(!new){
		printf("Allocation Error!\n");
		exit(-1);
	}
	new->data=data;
	new->next=NULL;
	if(!head){
		head = new;
		return head;
	}
	List * temp = head;

	while(temp->next){
		temp = temp->next;
	}
	temp->next=new;
	return head;

}

void printRecursive(List * head){
	if(!head){
		printf("Finished\n");
	}
	else{
		printf("%d\n",head->data);
		head=head->next;
		printRecursive(head);
	}
}

//delete functions
List * deleteFirstNode(List * head){
	if(!head){
		printf("Empty list");
		return head;
	}
	if(!head->next){
		free(head);
		head=NULL;
		return head;
	}else{
		List * temp = head;
		head=head->next;
		free(temp);
		temp=NULL;
		return head;
	}
}

List * deleteList(List * head){
	while(head){
		head = deleteFirstNode(head);
	}
	return head;	
}

List * deleteNode(List * head, DATA target){
	if(!head){
		printf("Empty List!\n");
		return head;
	}
	
	List * temp = head;
	List * prev;

	if(temp->data == target){
		temp = deleteFirstNode(head);
		return temp;
	}

	while(temp && temp->data != target){
		prev = temp;
		temp=temp->next;
	}

	if(!temp){
		printf("Target Not Found!\n");
		return head;
	}
	
	prev->next=temp->next;
	free(temp);
	temp=NULL;
	return head;
}

List * deleteAllOccurencesOfNode(List * head, DATA target){
	List * temp = head;

	while(temp){
		if(temp->data == target){
			head = deleteNode(head,target);
			temp = head;
			continue;
		}
		temp=temp->next;
	}
	return head;
}

// delete functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// add after function

void addAfterNode(List * node , DATA target){
	List * new = malloc(sizeof(List));
	new->data=target;
	new->next=node->next;
	node->next=new;
}

void addAfterFirstOccurence(List * head, DATA target,DATA value){
	List * temp = head;


	while(temp && temp->data != target){
		temp=temp->next;
	}
	if(!temp){
		printf("Not Found!\n");
	}else{
		addAfterNode(temp,value);
	}
	
}

void addAfterEveryOccurence(List * head, DATA target,DATA value){
	List * temp = head;
	
	while(temp){
		while(temp->data!=target){
			temp=temp->next;		
		}
		if(temp){
			addAfterNode(temp,value);
			temp=temp->next->next;
		}
	}
}

// add after functions

// add before functions

void addBeforeNode(List * node, DATA value){
	List * new = malloc(sizeof(List));
	*new = *node;
	node->next=new;
	node->data = value;
}

void addBeforeFirstOccurence(List * head,DATA target,DATA value){
	
	List * temp = head;
	
	while(temp && temp->data != target){
		temp=temp->next;
	}
	if(temp){
		addBeforeNode(temp,value);
	}

}

void addBeforeEveryOccurence(List * head,DATA target,DATA value){
	
	List * temp = head;

	while(temp){
		while(temp->data!=target){
		temp=temp->next;
		}
		if(temp){
			addBeforeNode(temp,value);
			temp=temp->next->next;
		}
	}
}
// addBefore
DATA scantarget(){
	DATA target;
	printf("Enter the target: ");
	scanf("%d",&target);
	return target;
}

DATA scanvalue(){
	DATA value;
	printf("Enter The Value: ");
	scanf("%d",&value);
	return value;
}

void printMenu(){
	printf("Choose One Of Ohese Options\n");
	printf("1. Add at First\n");
	printf("2. Add at Last\n");
	printf("3. Add after first occurence\n");
	printf("4. Add after every occurence\n");
	printf("5. Add before first occurence\n");
	printf("6. Add before every occurence\n");
	printf("7. Delete First Occurence\n");
	printf("8. Delete every Occurence\n");
	printf("9. Delete First node\n");
	printf("10. Delete List\n");
	printf("11. Print List\n");
	printf("12. Exit\n");
}
