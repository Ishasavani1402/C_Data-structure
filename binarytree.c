#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int info;
    struct tree *left, *right;
};

// create tree node
struct tree *createtreenode(int info)
{
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    root->info = info;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// preorder traversal
void preorder(struct tree *root)
{
    if (root != NULL)
    {
        printf("\n elements-%d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("\n elements=%d", root->info);
    }
}

void inorder(struct tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("\n elements-%d",root->info);
        inorder(root->right);
    }
}
int main()
{
    struct tree *root = createtreenode(10);
    struct tree *left = createtreenode(20);
    struct tree *right = createtreenode(30);

    root->left = left;
    root->right = right;
    left->left = createtreenode(40);
    left->right = createtreenode(50);
    right->left = createtreenode(60);
    right->right = createtreenode(80);
    printf("\n Preorder Traversal: ");
    preorder(root);
    printf("\n Postorder Traversal:");
    postorder(root);
    printf("\n inorder traversal");
    inorder(root);

    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(left);
    free(right);
    free(root);
    return 0;
}
