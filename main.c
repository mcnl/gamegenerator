#include <stdio.h>
#include <stdlib.h>

int tenI = 0;//This 'int' is i-th ten that is being generated 

/*Node structure: 
Pointer to the right, 
Pointer to the left, 
Placeholder for the value*/
struct node 
{
    struct node* left;
    struct node* right;
    int nodeValue;
};

/*The function that creates a new node, using dynamic 
allocation of memory sets the values of the pointer to NULL*/
struct node* newNode(int value) 
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->nodeValue = value;
    temp->left = temp->right = NULL;
    return temp;
}

/*The function that inserts the value on the tree*/
struct node* insertValue(int valueToInsert, struct node* root) 
{
    /*if the node is empty then add a new node in its place*/
    if(root == NULL)
    {
        tenI = tenI + 1; //this is to know that the i-th ten was created
        return newNode(valueToInsert);
    }
    /*if the node is not empty, 
    and the its value is bigger than the value that we want 
    to insert, we want the value on the left side of the tree*/
    else if(root->nodeValue > valueToInsert)
    {
        root->left = insertValue(valueToInsert, root->left);
    }
    /*if the node value is smaller than the value that we want 
    to insert, we want the value on the right side of the tree*/
    else if(root->nodeValue < valueToInsert)
    {
        root->right = insertValue(valueToInsert, root->right);
    }
    return root;
}
/*Print the Tree in Order (Basically this inform the game that was created)*/
void printTreeInOrder(struct node* root)
{
    if(root!=NULL)
    {
        printTreeInOrder(root->left);
        printf("%d ", root->nodeValue);
        printTreeInOrder(root->right);
    }
}

int main()
{
    int numberOftens, numberOfGames; //This is, respectively, the 'M' and 'N' that the specification order. These names were chosen just to make reading easier
    struct node* root = NULL;
    printf("Bem-Vindo Jogador, por favor insira os dados requisitados:\n");
    printf("Numero de Jogos que voce deseja fazer: \n");
    scanf("%d", &numberOfGames);
    printf("Numero de Dezenas que voce deseja fazer por jogo: \n");
    scanf("%d", &numberOftens);
    while(numberOftens < 6 || numberOftens > 15) //While to insure that the number of tens is between the valid interval 
    {
        printf("Por favor, digite um numero valido de Dezenas por jogos, entre 6 e 15: \n");
        scanf("%d", &numberOftens);
    }
    for (int i = 0; i < numberOfGames; i++) //Loop for the number of games
    {
        while(tenI<numberOftens) //this 'while' is a loop that is used to guarantee that the number generated is different from the rest (To not repeat tens)
        {
            root = insertValue((rand() % 60) + 1, root); //Values to 1 to 60
        }
        printf("[ ");
        printTreeInOrder(root);
        printf("]\n");
        //Reset the tree and the game
        tenI = 0;
        root = NULL;
    }  
    return 0;
}