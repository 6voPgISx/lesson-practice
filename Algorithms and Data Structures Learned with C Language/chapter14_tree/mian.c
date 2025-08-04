#include <stdio.h>
#include "tree.h"

int main(void)
{
    int x;
    Node* p;
    Node* root=NULL;

    printf("\n=データ登録=\n");
    while(1){
        printf("データを入力 (-1で終了)："); scanf("%d",&x);
        if(x==-1) break;
        else root=insert_tree(x,root);
    }
 
    printf("\n=データ表示=");
    printf("\n行きがけ順\t");
    traverse_pre_order(root);
    printf("\n通りがけ順\t");
    traverse_in_order(root);
    printf("\n帰りがけ順\t");
    traverse_post_order(root);
    printf("\nレベル順\t");
    traverse_level_order(root);
    
    printf("\n\n=データ検索=\n");
    while(1){
        printf("検索目標を入力 (-1で終了)："); scanf("%d",&x);
        if(x==-1) break;
        p=search_tree(x,root);
        if(p!=NULL) printf("見つかりました\n");
        else printf("見つかりませんでした\n");
    }

    free_tree(root);
    return 0;
}