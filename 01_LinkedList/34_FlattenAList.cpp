Node *merge2Lists(Node *h1, Node *h2){
    if(h1 == NULL){
        return h2;
    }
    
    if(h2 == NULL){
        return h1;
    }
    
    Node *newNode = new Node(-1), *p3 = newNode;
    
    while(h1 != NULL && h2 != NULL){
        if(h1 -> data < h2 -> data){
            p3 -> bottom = h1;
            h1 = h1 -> bottom;
            p3 = p3 -> bottom;
        }else{
            p3 -> bottom = h2;
            h2 = h2 -> bottom;
            p3 = p3 -> bottom;
        }
    }
    
    while(h1 != NULL){
        p3 -> bottom = h1;
        h1 = h1 -> bottom;
        p3 = p3 -> bottom;
    }
    
    while(h2 != NULL){
        p3 -> bottom = h2;
        h2 = h2 -> bottom;
        p3 = p3 -> bottom;
    }
    
    p3 -> bottom = NULL;
    return newNode -> bottom;
}


// Node *merge2Lists(Node *h1, Node *h2){
//     // recursive method to merge 2 lists
//     if(h1 == NULL){
//         return h2;
//     }
//     if(h2 == NULL){
//         return h1;
//     }
    
//     Node *result;
//     if(h1 -> data < h2 -> data){
//         result = h1;
//         result -> bottom = merge2Lists(h1 -> bottom, h2);
//     }else{
//         result = h2;
//         result -> bottom = merge2Lists(h1, h2 -> bottom);
//     }
    
//     return result;
// }



Node *flatten(Node *root)
{
   // TC O(N)     SC 0(K) K = number of lists to be flattened
   // base case
   if(root == NULL){
       return root;
   }

   // dividing the lists into two sublists that are to be merged and flattened
   Node *right = root -> next;
   
   // disconnecting the lists
   root -> next = NULL;
   
   // recursive call
   right = flatten(right);
   
   // merging the two sorted lists
   root = merge2Lists(root, right);
   
   return root;
}