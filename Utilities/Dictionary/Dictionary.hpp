#include "DoubleTemplatedDictionary.h"

using namespace KS::Dictionary;

#include <chrono>
#include <iostream>

template<typename __key_type__, typename __value_type__>
DoubleTemplatedDictionary<__key_type__, __value_type__>::DoubleTemplatedDictionary()
{
	m_keys.reserve(1);
	m_values.reserve(1);

	m_keys.push_back(__key_type__());
	m_values.push_back(__value_type__());

	m_defaultReturn = __value_type__();
	m_numEntries++;
}

template<typename __key_type__, typename __value_type__>
DoubleTemplatedDictionary<__key_type__, __value_type__>::DoubleTemplatedDictionary(__value_type__ _default)
{
	m_keys.reserve(1);
	m_defaultKey = __key_type__();
	m_keys.push_back(m_defaultKey);

	m_values.reserve(1);
	m_values.push_back(_default);

	m_defaultReturn = _default;

	m_numEntries++;
}

template<typename __key_type__, typename __value_type__>
DoubleTemplatedDictionary<__key_type__, __value_type__>::DoubleTemplatedDictionary(__key_type__ key, __value_type__ _value)
{
	m_keys.reserve(2);
	m_defaultKey = __key_type__();
	m_keys.push_back(m_defaultKey);

	m_values.reserve(2);
	m_defaultReturn = __value_type__();
	m_values.push_back(m_defaultReturn);

	m_keys.push_back(key);
	m_values.push_back(_value);

	m_numEntries += 2;
}

template<typename __key_type__, typename __value_type__>
DoubleTemplatedDictionary<__key_type__, __value_type__>::DoubleTemplatedDictionary(__key_type__ key, __value_type__  initValue, __value_type__ defaultValue)
{
	m_keys.reserve(2);
	m_defaultKey = __key_type__();
	m_keys.push_back(m_defaultKey);

	m_values.reserve(2);
	m_defaultReturn = defaultValue;
	m_values.push_back(defaultValue);

	m_keys.push_back(key);
	m_values.push_back(initValue);

	m_numEntries += 2;
}

template<typename __key_type__, typename __value_type__>
DoubleTemplatedDictionary<__key_type__, __value_type__>::DoubleTemplatedDictionary(__key_type__ initKey, __value_type__  initValue, __key_type__ defaultKey, __value_type__ defaultValue)
{
	m_keys.reserve(2);
	m_defaultKey = defaultKey;
	m_keys.push_back(defaultKey);

	m_values.reserve(2);
	m_defaultReturn = defaultValue;
	m_values.push_back(defaultValue);

	m_keys.push_back(key);
	m_values.push_back(initValue);

	m_numEntries += 2;
}

template<typename __key_type__, typename __value_type__>
void DoubleTemplatedDictionary<__key_type__, __value_type__>::addEntry(__key_type__ key, __value_type__ value)
{
	for (int i = 0; i < m_numEntries; i++)
	{
		if (m_keys[i] == key)
		{
			m_values[i] = value;
			return;
		}
	}

	m_keys.push_back(key);
	m_values.push_back(value);

	m_numEntries++;
}

template<typename __key_type__, typename __value_type__>
void DoubleTemplatedDictionary<__key_type__, __value_type__>::debugPrint(std::ostream &out) const
{
	for (int i = 0; i < m_numEntries; i++)
	{
		out << "Key: " << m_keys[i] << " | Value: " << m_values[i] << "\n";
	}
}

template<typename __key_type__, typename __value_type__>
void DoubleTemplatedDictionary<__key_type__, __value_type__>::alterDefaultKey(__key_type__ newDefaultKey)
{
	if (m_numEntries > 0)
	{
		m_keys[0] = newDefaultKey;
		m_defaultKey = newDefaultKey;
	}
}

template<typename __key_type__, typename __value_type__>
void DoubleTemplatedDictionary<__key_type__, __value_type__>::alterDefaultValue(__value_type__ newDefaultValue)
{
	if (m_numEntries > 0)
	{
		m_values[0] = newDefaultValue;
		m_defaultReturn = newDefaultValue;
	}
}

template<typename __key_type__, typename __value_type__>
std::pair<__key_type__, __value_type__> DoubleTemplatedDictionary<__key_type__, __value_type__>::extractDefaultInformation() const
{
	return (std::make_pair(m_defaultKey, m_defaultReturn));
}

template<typename __key_type__, typename __value_type__>
std::pair<__key_type__, __value_type__> DoubleTemplatedDictionary<__key_type__, __value_type__>::extractInformationAtIndex(const unsigned int index) const
{
	if (index < 0 || m_numEntries <= 0)
	{
		return (std::make_pair(m_defaultKey, m_defaultReturn));
	}
	else
	{
		return (std::make_pair(m_keys[index], m_values[index]));
	}
}

template<typename __key_type__, typename __value_type__>
unsigned int DoubleTemplatedDictionary<__key_type__, __value_type__>::getIndexOfKey(__key_type__ key) const
{
	for (int i = 0; i < m_numEntries; i++)
	{
		if (m_keys[i] == key)
			return key;
	}

	return NotFound;
}

template<typename __key_type__, typename __value_type__>
unsigned int DoubleTemplatedDictionary<__key_type__, __value_type__>::getIndexOfValue(__value_type__ value) const
{
	for (int i = 0; i < m_numEntries; i++)
	{
		if (m_values[i] == value)
			return i;
	}
	return NotFound;
}

template<typename __key_type__, typename __value_type__>
bool DoubleTemplatedDictionary<__key_type__, __value_type__>::removeIndexedEntry(int index)
{
	if (index <= 0 || index >= MaxSize)
		return false;

	m_keys.erase(m_keys.begin() + index);
	m_values.erase(m_values.begin() + index);

	m_numEntries--;

	return true;
}

template<typename __key_type__, typename __value_type__>
bool DoubleTemplatedDictionary<__key_type__, __value_type__>::removeFromKey(__key_type__ key)
{
	if (m_numEntries < 1 || m_defaultKey == key)
		return false;
	else
	{
		return (removeIndexedEntry(getIndexOfKey(key)));
	}
}

template<typename __key_type__, typename __value_type__>
bool DoubleTemplatedDictionary<__key_type__, __value_type__>::removeFromValue(__value_type__ value, DictEnum REMOVE_COMMAND = DICT_REMOVE_ALL_MATCHING_ENTRIES)
{
	if (m_numEntries < 1 || m_defaultReturn == value)
		return false;
	else
	{
		if (REMOVE_COMMAND == DICT_REMOVE_ALL_MATCHING_ENTRIES) {
			bool didremove = false;
			while (removeIndexedEntry(getIndexOfValue(value)))
			{
				didremove = true;
			}
			return didremove;
		}
		else
			return (removeIndexedEntry(getIndexOfValue(value)));
	}
}

template<typename __key_type__, typename __value_type__>
bool DoubleTemplatedDictionary<__key_type__, __value_type__>::alterKey(__key_type__ oldKey, __key_type__ newKey)
{
	if (oldKey == m_defaultKey)
		return false;
	
	for (int i = 1; i < m_numEntries; i++)
	{
		if (m_keys[i] == oldKey)
			m_keys[i] = newKey;
	}
}

template<typename __key_type__, typename __value_type__>
__value_type__& DoubleTemplatedDictionary<__key_type__, __value_type__>::operator[](const __key_type__ &key) const
{

	std::cerr << "\n\n\nWRITING\n\n\n" << std::endl;

	for (int i = 0; i < m_numEntries; i++)
	{
		if (m_keys[i] == key)
			return m_values[i];
	}
	
	return
		m_defaultReturn;
}

template<typename __key_type__, typename __value_type__>
__value_type__& DoubleTemplatedDictionary<__key_type__, __value_type__>::operator[](const __key_type__ &key)
{

	std::cerr << "\n\n\nREADING\n\n\n" << std::endl;

	for (int i = 0; i < m_numEntries; i++)
	{
		if (m_keys[i] == key)
			return m_values[i];
	}
	__value_type__ temp;
	return
		temp;
}

template<typename __key_type__, typename __value_type__>
bool DoubleTemplatedDictionary<__key_type__, __value_type__>::hasKey(__key_type__ key) const
{

	for (int i = 0; i < m_numEntries; i++)
	{
		if (m_keys[i] == key)
			return true;
	}
	
	return false;
}

template<typename __key_type__, typename __value_type__>
bool DoubleTemplatedDictionary<__key_type__, __value_type__>::hasValue(__value_type__ value) const
{
	for (int i = 0; i < m_numEntries; i++)
	{
		if (m_values[i] == value)
			return true;
	}
	return false;
}

template<typename __key_type__, typename __value_type__>
bool DoubleTemplatedDictionary<__key_type__, __value_type__>::hasKeyValuePair(__key_type__ key, __value_type__ value) const
{
	for (int i = 0; i < m_numEntries; i++)
	{
		if (m_keys[i] == key)
		{
			return (m_values[i] == value)
		}
	}
	
	return false;
}

template<typename __key_type__, typename __value_type__>
std::size_t DoubleTemplatedDictionary<__key_type__, __value_type__>::size() const
{
	return std::size_t(m_numEntries);
}

template<typename __key_type__, typename __value_type__>
bool DoubleTemplatedDictionary<__key_type__, __value_type__>::isEmpty() const
{
	return (m_numEntries < 2);
}

template<typename __key_type__, typename __value_type__>
void DoubleTemplatedDictionary<__key_type__, __value_type__>::emptyDictionary()
{
	while (m_numEntries > 1)
	{
		removeIndexedEntry(1);
	}
}
