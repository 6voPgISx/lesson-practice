// 二分木ノード 構造体宣言
typedef struct node{
   int data;
   struct node* left;
   struct node* right;
}Node;

// 関数プロトタイプ宣言
/*
  tree.c の中に関数の定義を書くたびに、
  そのプロトタイプ宣言を書き足していきましょう
 */
Node* new_node(int);
Node* insert_tree(int, Node*);
Node* search_tree(int, Node*);
void traverse_pre_order(Node*);
void traverse_in_order(Node*);
void traverse_post_order(Node*);
void free_tree(Node*);
void traverse_level_order(Node*);