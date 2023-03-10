
// Approach We will implement two stacks in an array you can give n/2 space to each stack but that would create /
// wastage of space in case one is filled more than the other so to utilize the space to full start one stack from start and other from last
void twoStacks :: push1(int x)
{
    if(top1 >= top2){
        return;
    }
    top1++;
    arr[top1] = x;
}
   
void twoStacks ::push2(int x)
{
    if(top1 >= top2){
        return;
    }
    top2--;
    arr[top2] = x; 
}
   
int twoStacks ::pop1()
{
    if(top1 == -1){
        return -1;
    }
    return arr[top1--];
}

int twoStacks :: pop2()
{
    if(top2 == size){
        return -1;
    }
    return arr[top2++];
}
