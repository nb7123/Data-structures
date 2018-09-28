# Simple binary search tree
simple binary search tree data structure c plus plus impletation

## delete Algorithm
a simple bstree(sort: left < right)  
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
* 1-delete node X12/X13(leaf node)  
`delete directly`
     
* 2-delete node X4/X7(only has left children or right children)
`let parent node left/right node pointer point X4/X7 only children`

* 3-delete node X2/X3(node has left and right children)
`1)find left children tree largest node, replace the delete node`
`2)delete the largest node parent pointer(here is X5)`  
or  
`1)find right children tree min node, replace the delete node`
`2)delete the largest node parent pointer(here is X6)`  
```
