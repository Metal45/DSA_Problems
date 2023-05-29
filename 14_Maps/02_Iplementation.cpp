//............................................................................IMPLEMENTATION...................................................................................................//

// Unordered map is implemeted using array/hashtable O(1) using hash funciton
// Ordered mapp is implementd using BST (LogN)


// Values are mapped in array using hash function 
// Hash Function -> 1. Hash Code
//                  2. Compression Function

// Hash Code -> Assigns a numeric value to the given input 
// Compression Function -> makes sure that the numeric value from hash code is the range of index of array


// Collision -> When two or more keys gets the same value it is called collision
// Collision Handling -> 1. Open Hasing -> You store all the keys of the that value in the form of liked list on the smae index 
//                       2. Closed Addressing -> You store the key at next free space.
//                              i.) Linear Probing -> You go on searching for the next free space linearly next to the current value/index.
//                              ii.) Quadratic Probing -> You go on searching for the next free space in a quadratic manner.



// Number of elements = n
// Number of free boxes = b
// Load Facotr -> Ratio = n/b
// A good hashfunction has load factor < 0.7


// TIME COMPLEXITY
// The opeations in this process of creating a hashmap that are not O(1) like in open hashing O(k), and finding values of keys
// through hash function is also considered O(1) because these as compared to the size of hash table O(N) is way less so (k <<< N) so
// can be approximated as O(1) time and rest worst cases are taken care becuase of a good hash function with ideal load factor.