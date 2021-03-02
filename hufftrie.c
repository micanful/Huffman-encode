#include "hufftrie.h"

Node *create_new(int weight, int value)
{
  Node *new = calloc(1, sizeof(Node));

  new->weight = weight;
  new->value = value;

  return new;
}

//Local function that assigns child nodes to a parent;
void children(Node *parent, Node *left, Node *right)
{
  parent->left = left;
  parent->right = right;
}

//local function which compares two elements, if return value > 0 elem1 is bigger
// if return value < 0 then elem2 is bigger
int compare(void *elem1, void *elem2)
{
	return ((Node *)elem1)->weight - ((Node *)elem2)->weight;
}


pqueue *create_pq(character *analysis)
{
  pqueue *pq = pqueue_empty(compare);
  Node *elem;

  for(int i = 0; i <= 255; i++){
    elem = malloc(sizeof(Node));
    elem->weight = analysis[i].frequence;
    elem->value = analysis[i].chara;

    pqueue_insert(pq, elem);
  }

  return pq;
}


Node *pq_to_tree(pqueue *pq)
{
  while(pqueue_is_empty(pq) == 0){
  Node *left = pqueue_inspect_first(pq);

  pqueue_delete_first(pq);

  //if pq is empty after taking out one element our tree is done
  if(pqueue_is_empty(pq) != 0){
    return left;
  }

  Node *right = pqueue_inspect_first(pq);
  pqueue_delete_first(pq);

  Node *new = create_new(left->weight + right->weight, -1);

  children(new, left, right);

  pqueue_insert(pq, new);
  }

  //Only used if pq is empty
  Node *empty_pq = create_new(0, 0);

  return empty_pq;
}


void kill_tree(Node *tree)
{
  if(is_leaf(tree) == 0){
    kill_tree(tree->left);
    kill_tree(tree->right);
  }
  free(tree);
}


int is_leaf(Node *node)
{
  if(node->value < 0 || node->value > 255){
    return 0;
  }
  else
  {
    return 1;
  }
}
