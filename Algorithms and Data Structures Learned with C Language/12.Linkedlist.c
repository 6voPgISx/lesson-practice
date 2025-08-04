#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
    struct node* next;
    int data;
}Node;
 
Node* add_node(Node* next, int data);
 
int main(void)
{
    Node* head=NULL;
    Node* p;
    Node* q;
    int data;
 
    while(1){
        printf("整数データ入力(0で終了):");
        scanf("%d",&data);
        if(data==0) break;
        head=add_node(head,data);
    }
    
    // while (1) {
    //     printf("整数データ入力(0で終了):"); // Prompt: "Enter integer data (0 to end):"
    //     scanf("%d", &data);
    //     if (data == 0) break;

    //     if (tail == NULL) { // If the list is empty
    //         tail = head = add_node(NULL, data);
    //     } else { // Add to the end of the list
    //         tail = tail->next = add_node(NULL, data);
    //     }
    // }
 
    printf("\n＝データの探索＝\n");
    while(1){
        printf("探索目標入力(0で終了)：");
        scanf("%d",&data);
        if(data==0)break;
        if(head->data==data){
            printf("見つかりました\n");
            continue;
        }
        for(q=head,p=q->next;p!=NULL;q=q->next,p=q->next){
            if(p->data==data)break;
        }
        if(p==NULL)printf("見つかりませんでした\n");
        else{
            printf("見つかりました\n");
            q->next=p->next;
          	p->next=head;
            head=p;
        }
    }


    printf("\n＝リストのデータ＝\n");
    for( p=head; p!=NULL; p=p->next ) printf("%d\t", p->data);
    printf("\n");
 
    while(head!=NULL){
        p=head->next;
        free(head);
        head=p;
    }
    return 0;
}


Node* add_node(Node* next, int data)
{
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->next = next;
    p->data = data;
    return p;
}