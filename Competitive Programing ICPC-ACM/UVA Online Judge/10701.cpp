/*
preorder: root, left,right
inorder: left,root, right
postorder: left, right,root

input: numero_de_nodos preorder inorder
3
3 xYz Yxz
3 abc cba
6 ABCDEF CBAEDF

Output: Post Order
Yzx
cba
CBEFDA
*/

#include <cstdio>
#include <string>
#include <iostream>

typedef struct node
{
    char c;
    node* l;
    node* r;
}Node;

std::string preorder;

void printPostOrder(Node* t)
{
    if(t == 0)
        return;
    printPostOrder(t->l);

    printPostOrder(t->r);

    printf("%c",t->c);
}

Node* createNode(std::string inorder)
{
    if(inorder.size() == 0)
    {
        return 0;
    }
    Node* n = new Node();

    n->c = preorder.at(0);

    char a = preorder.at(0);
    preorder = preorder.substr(1);

    if(preorder.size() != 0){
        n->l = createNode(inorder.substr(0,inorder.find_first_of(n->c)));
        n->r = createNode(inorder.substr(inorder.find_first_of(n->c)+1,inorder.size()));
    } else {
        n->l = 0;
        n->r = 0;
    }

    return n;
}

int main()
{
    int num;
    int num_nodes;
    std::string inorder;

    scanf("%d", &num);
    while(num != 0)
    {
        scanf("%d",&num_nodes);
        std::cin >> preorder;
        std::cin >> inorder;
        Node* tree = createNode(inorder);
        printPostOrder(tree);
        printf("\n");
        num--;
    }
    return 0;
}
