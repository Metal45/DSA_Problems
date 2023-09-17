// KosaRaju's algo is used to determine and count the number of strongly connected components in a directed graph

// Approach -> 

// a.) first major task is to differenciate b/w the SCC and isolating them  -> (reversing the edges)

// 1. You can not differenciate between the SCC using dfs as it will simply start from the src node and will reach the des node
// 2. So now the question arises how can you differenciate and isolate a SCC from rest of the graph
// 3. Visulaise SCC as a single nodes and they can go to the other SCC'S (strivers video), SCC1 -> SCC2 -> SCC3 -> SCC4
// 4. Now when you reverse the edges of the current graph u have it will become something like this SCC1 <- SCC2 <- SCC3 <- SCC4
// 5. Since the nodes inside the SCC's are reachable form anywhere and are connected to each other reversing the edges won't have any affect on them


// b). You need to traverse the SCC in such a way that for one dfs call you only cover the particular nodes of the current SCC 
//     if u will do a dfs call on a SCC node that is connected to some other node of a different SCC u will loose track of the current SCC
//     so to avoid that u need to do dfs calls in such a order that every time a dfs call ends, only the nodes of a particular SCC is covered 
//     that means no node of that SCC has an outgoing edge to any other SCC except itself.


// 1. This gives us an idea to perform dfs calls in the sorted order of completion time
// 2. when we will sort the edges in order of completion time and will perform the dfs 
// 3. we can keep track of the dfs calls made
// 4. Take the example of this -> SCC1 <- SCC2 <- SCC3 <- SCC4
// 5. if you start making the dfs call from SCC4 you will cover the entire graph in 1 dfs call and will not be able to isolate the SCC 
// 6. where as if you will start making dfs call from SCC1 it will visit all the nodes of SCC1 nd a new call will be made for SCC2 making it isolated from rest
// 7. similarly from 2, 3, 4
// 8. so sort the edges according to the completion time and then make dfs calls so whenever one dfs call ends it covers one SCC 


// 3 STEPS -> 1. SORT THE EDGES
//            2. REVERSE THE GRAPH
//            3. COUNT THE NUMBER OF DFS CALLS to count the number of SCC in that graph
