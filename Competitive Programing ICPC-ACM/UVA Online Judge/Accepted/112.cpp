//Problem 112 UVA ONLINE - Tree Summing
//Leonardo Quatrin Campagnolo
//Using algorithm of SUM

#include <cstdio>
#include <cassert>

typedef struct node
{
    int val;
    node* l;
    node* r;
} Node;

Node* parse_node()
{
    Node* n = new Node;

    int ret = scanf(" (%d", &n->val);
    if (ret != 1)
    {
        scanf(" )");
        return 0;
    }

    n->l = parse_node();
    n->r = parse_node();

    scanf(" )");

    return n;
}

bool match_sum( Node* tree, int num, int v)
{
    if (tree == 0)
        return false;

    bool ret = false;
    if(tree->l == 0 && tree->r == 0)
    {
       return (v + tree->val == num);
    }
    if(tree->l != 0)
    {
       ret = ret || match_sum(tree->l, num, v + tree->val);
    }
    if(tree->r != 0)
    {
       ret = ret || match_sum(tree->r, num, v + tree->val);
    }
    return ret;
}

int main()
{
    int num = -1;

    while (scanf("%d", &num) == 1)
    {
        Node* tree = parse_node();

        if (match_sum(tree, num, 0))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }

    return 0;
}
