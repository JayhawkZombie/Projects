#ifndef DBL_TEMP_DICT
#define DBL_TEMP_DICT

#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <iostream>

namespace KS
{
	namespace Dictionary
	{

		typedef enum { DICT_REMOVE_ALL_MATCHING_ENTRIES, DICT_REMOVE_FIRST_OCCURRENCE } DictEnum;

		template <typename __key_type__, typename __value_type__>
		class DoubleTemplatedDictionary
			/*  An ineffecient dictionary!
			It works, and that's what matters!
			The dictionary is always guarenteed to maintian an entry with the key "__default__" with the value provided by the default constructor
			of the template type
			Attempts to remove the default key will simply fail, but no exception will be thrown
			*/
		{
		public:
			/*  
			5 Different constructors provide 5 ways to create a dictionary
			1 - With no given defaults - the dictionary will construct its own
			2 - With a default value given, but not default key - the dictionary will construct its own default key
			3 - With an initial key and initial value, but no default key or default value - the dictionary will construct its own default key and value
			4 - With an initial key, inital value, and a default value, but no default key - the dictionary will construct its own default key
			5 - With an initial key, initial value, key to access the default entry, and value to give to the default entry
			*/
			DoubleTemplatedDictionary();
			DoubleTemplatedDictionary(__value_type__ defaultValue);
			DoubleTemplatedDictionary(__key_type__ initKey, __value_type__  initValue);
			DoubleTemplatedDictionary(__key_type__ key, __value_type__  initValue, __value_type__ defaultValue);
			DoubleTemplatedDictionary(__key_type__ key, __value_type__  initValue, __key_type__ initKey, __value_type__ defaultValue);

			/* Overloaded operatoras */
			__value_type__ operator[](const __key_type__ &) const;
			__value_type__ & operator[](const __key_type__ &);


			/* Utilities to add entries */
			void addEntry(__key_type__ key, __value_type__ value);

			/* Utilities to remove entries */
			bool removeFromKey(__key_type__ keyToRemove);
			bool removeFromValue(__value_type__ valueToRemove, DictEnum REMOVE_COMMAND = DICT_REMOVE_ALL_MATCHING_ENTRIES);
			bool removeIndexedEntry(int index);

			/* Utilities to alter entries */
			void alterDefaultKey(__key_type__ newDefaultKey);
			void alterDefaultValue(__value_type__ newDefaultValue);
			bool alterKey(__key_type__ oldkey, __key_type__ newKey);

			/* Utilities to extract information about the dictionary */
			std::pair<__key_type__, __value_type__> extractDefaultInformation() const;
			std::pair<__key_type__, __value_type__> extractInformationAtIndex(const unsigned int index) const;
			unsigned int getIndexOfKey(__key_type__ key) const;
			unsigned int getIndexOfValue(__value_type__ value) const;
			bool hasKey(__key_type__ key) const;
			bool hasValue(__value_type__ value) const;
			bool hasKeyValuePair(__key_type__ key, __value_type__ value) const;

			/* Debugging Utilities */
			void debugPrint(std::ostream &out) const;

			/* Static constants */
			static const std::size_t NotFound = INT_MAX;
			static const std::size_t MaxSize = INT_MAX - 1;

		private:
			__value_type__ m_defaultReturn;
			__key_type__ m_defaultKey;
			std::vector<__key_type__> m_keys;
			std::vector<__value_type__> m_values;
			int m_numEntries;


		};

#include "DoubleTemplatedDictionary.hpp"
	}
}

#endif
