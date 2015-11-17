###A not necessarily effecient dictionary

###"Because I Can" kind of project

_____________________________________________________________________________________-
####Provides a templated Dictionary implementation
####Key-Value pairs are stored
####The following are guarenteed by the Dictionary:
-  A default key and default value will always be present and able to be extracted and altered, but never removed
-  A maximum size is enforced, determined to be INT_MAX - 1 at compile time
-  Range-based for-loop iteration is in-progress
-  The Key-Value pair is guarenteed to stay in parallel in the dictionary
    *  Meaning, ```values[i]``` and ```keys[i]``` will maintain their parallel existance - they will never be out of order
-  The dictionary is FCFS, meaning that entries added later will exist with higher indices

-  Entries can be modified using the subscript operator
    * Both reading entried and the modification of the values of key-value pairs is supported
