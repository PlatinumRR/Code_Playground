//
//  
//  TreeNode
//
//  Created by 沈耀东 on 4/27/17.
//  Copyright © 2017 Yadong Shen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//TreeNode
typedef struct TreeNode_
{
  int value;
  struct TreeNode_ * left;
  struct TreeNode_ * right;
}TreeNode;

//Declearation
static TreeNode * TreeNode_Construct (int Val);
TreeNode * TreeNode_Insert (TreeNode * tn, int Val);
void TreeNode_Destroy (TreeNode * tn);



static TreeNode * TreeNode_Construct (int Val)
{
  TreeNode * NTreeNode;
  
  NTreeNode = malloc(sizeof(TreeNode));
  NTreeNode -> left = NULL;
  NTreeNode -> right = NULL;
  NTreeNode -> value = Val;
  
  return NTreeNode;
}


TreeNode * TreeNode_Insert (TreeNode * tn, int Val)
{
  if (tn == NULL)
  {
    //creat a treenode when it is empty
    return TreeNode_Construct (Val);
  }
  
  if (tn -> value == Val)
  {
    //Do not insert the same value
    return tn;
  }
  
  if (tn -> value > Val)
  {
    tn -> left  = TreeNode_Insert (tn -> left, Val);
  }
  else
  {
    tn -> right = TreeNode_Insert (tn -> right, Val);
  }
  
  return tn;
}


void TreeNode_Destroy (TreeNode * tn)
{
  if (tn == NULL)
  {
    return;
  }
  
  TreeNode_Destroy (tn -> left);
  TreeNode_Destroy (tn -> right);
  
  free(tn);
}


void TreeNode_InOrderPrint (TreeNode * tn)
{
  if (tn == NULL)
  {
    return;
  }
  
  TreeNode_InOrderPrint (tn -> left);
  printf("%d\t", tn -> value);
  TreeNode_InOrderPrint (tn -> right);
}






