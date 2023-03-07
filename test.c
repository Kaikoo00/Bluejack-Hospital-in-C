//Edrico Putra Pramana
//LB20 - 2602078133

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node{
	char name[25];
    int age;
    char desc[60];
    char status[10];
	struct node *next;
	struct node *prev;
};
struct node *head,*tail;
int data_count;

void display(){
    if(head==NULL){
        printf("There's no queue yet!\n");
        system("pause");
        system("cls");
        return;
    }

    int i=1;
    printf("Patient List:\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|No  | Name                      | Age   | Description                                                | Code    |\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    for(struct node *curr=head; curr!=NULL; curr=curr->next){
        printf("%-4d | %-25s | %5d | %-60s| %-6s |\n", i, curr->name, curr->age, curr->desc, curr->status);
        i++;
    }
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    system("pause");
    system("cls");
    return;
}

void input(char *name, int *age, char *desc, char *status){
    do{
        printf("Input patient's name[4-25 characters]: ");
        scanf("%[^\n]", name);getchar();
        if(strlen(name)>=4 && strlen(name)<=25){
            break;
        }
    }while(1);

    while(1){
        printf("Input patient's age[0 year old or more]: ");
        scanf("%d", age); getchar();
        if(*age>=0)break;
    }
    do
    {
        printf("Input patient's description[>= 6 characters]: ");
        scanf("%[^\n]", desc);getchar();
        if(strlen(desc)>= 6){
            break;
        }
    } while (1);
    
    while(1){
        printf("Input code [Red | Yellow | Green]: ");
        scanf("%s", status); getchar();
        if(!strcmp(status, "Red") || !strcmp(status, "Yellow") || !strcmp(status, "Green")){
            break;
        }
    }
    system("cls");
}

void CreateLinkedList(char *name, int age, char *desc, char *status){
	struct node *newnode =(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    newnode->age = age;
    strcpy(newnode->desc, desc);
    strcpy(newnode->status, status);
	newnode->next=NULL;
	head=newnode;
	tail=head;
	head->next=tail;head->prev=NULL;
	tail->prev=head;tail->next=NULL;
    data_count++;
}

void insert_tail(char *name, int age, char *desc, char *status){
	struct node *newnode =(struct node*)malloc(sizeof(struct node));
	strcpy(newnode->name, name);
    newnode->age = age;
    strcpy(newnode->desc, desc);
    strcpy(newnode->status, status);
	newnode->next = NULL;
	newnode->prev = tail;
	tail->next=newnode;
	tail = newnode;
    data_count++;
}

void delete_head(){
    if(head==NULL){
        printf("Please create a new linked list first.\n");
        return;
    }

    if(head==tail){
        head=NULL;
        tail=NULL;
        printf("There's no queue left.\n");
        return;
    }
	head = head->next;
	head->prev = NULL;
    data_count--;
}

void print_menu(){
    printf("=================\nBluejack Hospital\n=================\n1. Insert\n2. View\n3. Next Queue\n4. Exit\n>>");
}

int main()
{
    char name[25], desc[60], status[10];
    int age, ch;
    while(1){
        print_menu();
        scanf("%d", &ch); getchar();
        if(0>ch || ch>4){
            system("cls");
            continue;
        }
        if(ch==1){
            input(name, &age, desc, status);
            if(data_count==0)CreateLinkedList(name, age, desc, status);
            else insert_tail(name, age, desc, status);
        }
        if(ch==2){
            system("cls");
            display();
        }
        if(ch==3){
            if(head==NULL){
                printf("\nThere's no queue yet!\n");
                system("pause");
                system("cls");
                continue;
            }
            system("cls");
            printf("Name\t        : %s\n", head->name);
            printf("Age\t        : %d\n", head->age);
            printf("Description\t: %s\n", head->desc);
            printf("Code\t        : %s\n", head->status);
            delete_head();
            system("pause");
            system("cls");
        }
        if(ch==4){
            system("cls");
            printf("Thankyou for using our program!\n");
            exit(1);
        }
    }
    return 0;
}
