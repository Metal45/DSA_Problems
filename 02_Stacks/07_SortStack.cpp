// Approach -> To sort the stack store the first element and then ask recursion to sort the rest of the stack and insert the top at the correct location
// TC O(N2) SC O(N)
 
// If the element to be inserted is greater simply insert else store the element pop it and check for the next element
// do this until you find the correct location to insert
void InsertSorted(stack<int> &s, int val){
    // inserting if the val is greater than the top of stack 
    if(s.empty() || s.top() < val){
        s.push(val);
        return;
    }
    
    // storing the top
    int x = s.top();
    s.pop();
    
    // recursive call
    InsertSorted(s, val);
    
    // pushing the element to its right place
    s.push(x);
}

void SortedStack :: sort()
{
   // Base Case 
   if(s.empty()){
       return;
   }
   
   // Storing the top element of stack
   int val = s.top();
   s.pop();
   
   // recursive call
   sort();
   
   // Inserting the element in sorted order
   InsertSorted(s, val);
}