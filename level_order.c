/*
Level order traversal of tree is same as BFS in graph. Implement level order travarsal.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

void insert_binary_search_tree (struct node **root, int val)
{
  struct node *runner;
  struct node *new_node = (struct node *) malloc (sizeof (*new_node));
  new_node->data = val;
  new_node->left = NULL;
  new_node->right = NULL;

  //The tree is empty
  if (!*root) {
    *root = new_node;
    return;
  }

  runner = *root;
  while (runner) {
    if (val >= runner->data) {
      if (runner->right) {
        runner = runner->right;
      } else {
        runner->right = new_node;
        break;
      }
    } else {
      if (runner->left) {
        runner = runner->left;
      } else {
        runner->left = new_node;
        break;
      }
    }
  }
}

#define QUEUE_SIZE 100

int level_order (struct node *root)
{
  struct node *runner;
  struct node *queue[QUEUE_SIZE] = {0};
  int start_ix = 0, end_ix = 0;

  if (!root)
    return 0;

  //insert root to queue
  queue[end_ix++] = root;

  //queue is not empty
  while (end_ix > start_ix) {
    //dequeue
    runner = queue[start_ix++];
    printf ("%d ", runner->data);
    //insert chieldren to queue
    if (end_ix >= QUEUE_SIZE) {
      printf ("Queue is full. Please increase the queue size\n");
      return 1;
    }
    if (runner->left)
      queue[end_ix++] = runner->left;
    if (runner->right)
      queue[end_ix++] = runner->right;
  }
  return 0;
}

void main ()
{
  struct node *root = NULL;

  insert_binary_search_tree (&root, 15);
  insert_binary_search_tree (&root, 25);
  insert_binary_search_tree (&root, 30);
  insert_binary_search_tree (&root, 20);
  insert_binary_search_tree (&root, 35);
  insert_binary_search_tree (&root, 40);
  insert_binary_search_tree (&root, 1);
  insert_binary_search_tree (&root, 0);
  insert_binary_search_tree (&root, 10);
  insert_binary_search_tree (&root, 12);
  insert_binary_search_tree (&root, 14);
  insert_binary_search_tree (&root, 11);

  level_order (root);
  printf ("\n");
}