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
-  Currently, the following must be given by any type used for keys/values
    * operator ==
    * operator = 
    * copy constructor
    * zero-argument constuctor

###Structure
R = Removable
M = Mutable

|Keys|Values|Properties|Index|
|:---|:-----|----------|-----|
|defaultKey|defaultValue|M|0|
|key0|value0|RM|0|
|key1|value1|RM|1|
|... | ...  |RM|.|
|keyN|valueN|RM|N - 1|

###Available Functions

- CO = Constructor
- C = const qualified
- S = static
- H = helper
- M = Manipulating

R<type> - Return Type
   - CO = Constructor
   - B = Bool
   - U = Unsigned Int
   - S = Size_t
   - V = Void
   - _VT_ = ValueType (chosen template type)
   - _KT_ = KeyType (chosen template type)
   - SP = std::pair

|Function Name| Return Type | Arguments | Properties | Description |
|:------------|:------------|:----------|:-----------|:------------|
|```DoubleTemplatedDictionary()```| CO | None | CO | No-Arg Constructor |
|```DoubleTemplatedDictionary()```| CO | ```_VT_``` DefaultValue | CO | Constructor - Gives defaultValue to the dictionary |
|```DoubleTemplatedDictionary()```| CO | ```_KT_``` InitialKey, ```_VT_``` InitialValue | CO | Constructor - sets inital key/value pair (not the default pair) |
|```DoubleTemplatedDictionary()```| CO | ```_KT_``` InitialKey, ```_VT_``` InitialValue, ```_VT_``` DefaultValue | CO | Constructor - sets initial key/value pair and the default value |
|```DoubleTemplatedDictionary()```| CO | ```_KT_``` InitialKey, ```_VT_``` InitialValue, ```_KT_``` DefaultKey, ```_VT_``` DefaultValue | CO | Constructor - sets initial key/value pair and manually sets both the default key and default value |
|```addEntry()```| Void | ```_KT_``` newKey, ```_VT_``` newValue | Mutates | Adds an entry - Replaces existing value if the key already exists |
|```removeIndexedEntry()```| Bool | ```U``` index | Mutates | Removed the key/value pair assocaited with the index - returns true if successful, or false if either the entry does not exist or the index given was 0 |
|```hasKey()```| Bool | ```_KT_``` key | Const | Returns true if the dictionary has a key that matches the given |
|```hasValue()```| Bool | ```_VY_``` value | Const | Returns true if the dictionary contains a value that matches the given |
|```hasKeyValuePair()```| Bool | ```_KT_``` key, ```_VT``` value | Const | Returns true if the dictionary contains the given Key-Value pair |
|```alterDefaultKey()```| Void | ```_KT_``` newDefaultKey | Mutates | Changes the key associated with the default entry |
|```alterDefaultValue()```| Void | ```_VT_``` newDefaultValue | Mutates | Changes the value associated with the default entry |
|```alterKey()```| Bool | ```_KT__``` oldKey, ```_KT_``` newKey | Mutatues | Returns true if the change was implemted, false if the key does not exist or the was identical to that of the default entry |
|```isEmpty()``` | Bool | None | Const | Returns true if the dictionary contains only the default key-value pair |
|```size()``` | Size_t | None | Const | Returns the number of entries in the dictionary, including the key-value pair |
|```removeFromKey()```| Bool | ```_KT_``` key | Mutates | Removes the key-value pair associated with the given key - returns true if removal was successful, false otherwise. Does not allow removal of the default key-value pair |
|```removeFromValue()```| Bool | ```_VT_``` value, COMMAND (REMOVE_ALL_ENTRIES or REMOVE_FIRST_INSTANCE) | Mutates | Removes either the first key-value pair with a value that matches the given or all instances, insicated by COMMAND |
|```extractDefaultInformation()```| std::pair | None | Const | Returns a std::pair with the key and value of the default entry |
|```extractInformationAtIndex()```| std::pair | ```U``` index | Const | Returns a std::pair with the key-value pair at the indicated index - will return the default key-value pair if the index given is < 0 or out of bounds |

####Example
```c++
int main()
{
   DoubleTemplatedDictionary<std::string, int> myDict; //No defaults are given
   DoubleTemplatedDictionary<std::string, int> myDict2(5); //Default value = 5
   DoubleTemplatedDictionary<std::string, int> myDict3("InitialKey", 7); //Initial key and value (NOT THE DEFAULT KEY AND VALUE)

}
