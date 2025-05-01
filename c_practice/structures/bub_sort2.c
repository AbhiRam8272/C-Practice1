#include<stdio.h>
#include<string.h>
typedef struct details{
    char name[50];
    float price;
    int pages;
}book;

void sort(book sb[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(sb[i].name, sb[j].name) > 0) {
                book temp = sb[i];
                sb[i] = sb[j];
                sb[j] = temp;
            }
        }
    }
}
int main(){
    int a;
    printf("Enter no.of books: ");
    scanf("%d",&a);
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    book b[a];
    for(int i=0;i<a;i++){
        printf("Enter the name of book%d: ",i+1);
        fgets(b[i].name,50,stdin);
        b[i].name[strcspn(b[i].name, "\n")] = '\0';
        printf("enter the price of the book%d: ",i+1);
        scanf("%f",&b[i].price);
        printf("Enter the no.of pages in book%d: ",i+1);
        scanf("%d",&b[i].pages);
        printf("\n");
        while ((getchar()) != '\n' && getchar() != EOF);
    }
    printf("Details of %d books entered:\n",a);
    for(int i=0;i<a;i++){
        printf("Book %d:\n",i+1);
        printf("NAME: %s\n",b[i].name);
        printf("PRICE: %.1f\n",b[i].price);
        printf("NO.OF PAGES: %d\n",b[i].pages);
        printf("\n");
    }
    printf("\nList of books in lexicographical order:\n");
    sort(b,a);
    for(int i=0;i<a;i++){
        printf("Book %d:\n",i+1);
        printf("NAME: %s\n",b[i].name);
        printf("PRICE: %.1f\n",b[i].price);
        printf("NO.OF PAGES: %d\n",b[i].pages);
        printf("\n");
    }
}