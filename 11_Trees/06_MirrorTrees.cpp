// check if the givern trees are symmetric or not 


// same as last question (equal trees) just don't traverl to same sides instead traverese opposite
// when you go to 1.) p -> left go to q -> right 
//                2.) p -> right go to q -> left 

bool areMirror(BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    if(p == NULL && q == NULL){
        return true;
    }
    
    if(p == NULL || q == NULL || p -> data != q -> data){
        return false;
    }

    bool leftans = areMirror(p -> left, q -> right);
    bool rightans = areMirror(p -> right, q -> left);

    return leftans && rightans;
}
