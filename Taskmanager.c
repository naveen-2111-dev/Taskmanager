#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Item {
    char name[20];
    char description[200];
};

struct Stack {
    struct Item item[MAX_SIZE];
    int top;
} s;

void initStack() {
    s.top = -1;
}

int edit(){
    char name[20], newname[20], newdesc[50];
    int i;

    printf("enter the name to task to be edited ");
    scanf("%s", name);

    getchar();
    for (i = s.top ; i>=0 ; i--){
        if(strcmp(s.item[i].name, name) == 0) {
            printf("this is your previous data name:[%s] description:[%s]",s.item[i].name,s.item[i].description);
            printf("\nenter a new description: ");
            scanf("%[^\n]", newdesc);
            printf("\nenter a new name for this task enter zero to skip: ");
            scanf("%s", newname);
            if (strcmp(newname, "zero") != 0) {
                strcpy(s.item[i].name, newname);
            }
            
            strcpy(s.item[i].description,newdesc);
            printf("Task edited successfully!\n");
            return 0;
        }
    }
    printf("task not found!!!");
    return 1;
}

int Remove(){
    char name[20];
    int i;

    printf("enter the name to be removed: ");
    scanf("%s",name);
    if(s.top == -1){
        printf("nothing here/...");
        return 0;
    }
    printf("item popped succesfully!/..");
    s.top--;
}

int Search(){
    char name[20];
    int i;

    printf("enter the name to be searched: ");
    scanf("%s", name);
    if(s.top == -1){
        printf("nothing here/...");
        return 0;
    }

    for (i = s.top ; i>=0 ; i--){
        if (strcmp(s.item[i].name, name) == 0){
            printf("%s name found!", name);
            return 0;
        }
    }
    printf("name not found!/...");
}

int View(){
    int i;
    if(s.top == -1){
        printf("nothing here");
        return 0;
    }

    printf("~~~ to-do ~~~");
    printf("\n name | description");
    for (i = s.top; i >= 0;i--){
        printf("\n %s | %s \n", s.item[i].name, s.item[i].description);
    }
}

void Push(char *name, char *description) {
    if (s.top == MAX_SIZE - 1) {
        printf("Storage full\n");
        return;
    }

    s.top++;
    strcpy(s.item[s.top].name, name);
    strcpy(s.item[s.top].description, description);
    printf("Added to stack successfully\n");
}

void TaskChoice() {
    printf("\n 1. Add Task\n 2. Remove Task\n 3. Edit Task\n 4. Search Task\n 5. view Task\n");
}

void Options(int Choice) {
    char TaskName[20], description[200];
    switch (Choice) {
        case 1:
            printf("Add name of the task: ");
            scanf("%s", TaskName);
            printf("\nTask description: ");
            scanf(" %[^\n]", description); 
            Push(TaskName, description);
            break;
        case 2:
            Remove();
            break;
        case 3:
            edit();
            break;
        case 4:
            Search();
            break;
        case 5:
            View();
            break;
        default:
            printf("Enter a valid choice\n");
            break;
    }
}

int main() {
    int Choice;
    initStack();
    while(1){
        TaskChoice();
        printf("\nEnter your choice: ");
        scanf("%d", &Choice);
        Options(Choice);
    }
    return 0;
}
