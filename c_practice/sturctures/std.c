#include<stdio.h>
#include<string.h>
static int a;
typedef struct students{
    char name[50];
    int age;
    char dob[15];
    float per;
}std;
typedef union student{
    struct com{
        char name[50];
        int age;
        char dob[15];
        float per;
    }c1;
}uni;

int main(){
    extern int a;
    int x,y;
    uni abc;
    printf("Enter no.of students: ");
    scanf("%d",&a);
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    std s[a];
    for(int i=0;i<a;i++){
        printf("Enter the name of student%d: ",i+1);
        fgets(s[i].name,50,stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';
        printf("enter the age of student%d: ",i+1);
        scanf("%d",&s[i].age);
        printf("Enter the D.O.B of student%d in dd-mm-yyyy format: ",i+1);
        scanf("%s",s[i].dob);
        printf("Enter the overall percentage of student%d: ",i+1);
        scanf("%f",&s[i].per);
        printf("\n");
        while ((getchar()) != '\n' && getchar() != EOF);
    }
    printf("Details of %d students entered:\n",a);
    for(int i=0;i<a;i++){
        printf("Student %d:\n",i+1);
        printf("NAME: %s\n",s[i].name);
        printf("AGE: %d\n",s[i].age);
        printf("D.O.B: %s\n",s[i].dob);
        printf("OVERALL PERCENTAGE: %.3f\n",s[i].per);
        printf("\n\n");
    }

    printf("Enter the two students numbers to compare:\n");
    scanf("%d%d",&x,&y);
    if(strcmp(s[x-1].name,s[y-1].name)==0){
        strcpy(abc.c1.name, s[x - 1].name);
    }
    if(s[x-1].age==s[y-1].age){
        abc.c1.age=s[x-1].age;
    }
    if(strcmp(s[x-1].dob,s[y-1].dob)==0){
        strcpy(abc.c1.dob, s[x - 1].dob);
    }
    if(s[x-1].per==s[y-1].per){
        abc.c1.per=s[x-1].per;
    }
printf("\n\n");
    printf("Similarities in the students %d,%d are:\n",x,y);
    printf("NAME: %s\n",abc.c1.name);
    printf("AGE: %d\n",abc.c1.age);
    printf("D.O.B: %s\n",abc.c1.dob);
    printf("OVERALL PERCENTAGE: %.3f\n",abc.c1.per);

    return 0;
}