# BTree-cpp
simple b-tree data structure c plus plus impletation

## delete Algorithm
a simple btree(sort left < right)  
```  
                        X1
                     /     \
                    X2      X3
                  /   \    /   \
                 X4   X5  X6   X7
                /                \
               X8               X11
                 \             /
                X12          X13
``` 
* 1-delete node X4(leaf node)
`delete directly`
     
* 2-delete node X4/X7(only has left child or right child)
`let parent node left/right node pointer point X4/X7 only child`
     
*3-delete node X2/X3(node has left and right child)
`1)find left child tree largest node, replace the delete node`
`2)delete the largest node parent pointer(here is X5)`  
or
`1)find right child tree min node, replace the delete node`
`2)delete the largest node parent pointer(here is X6)`
```
