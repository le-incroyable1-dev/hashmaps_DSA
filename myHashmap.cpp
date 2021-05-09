#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// time to implement your own hashmap !
template <typename V>
class MapNode
{
public:
	string key;
	V value;
	MapNode* next;

	MapNode(string key, V val)
	{
		this->key = key;
		this->value = val;
		next = NULL;
	}

	~MapNode()
	{
		delete next;
	}

};



template <typename V>
class ourmap
{
	MapNode<V>** buckets;
	int size;
	int numBuckets;

	//this actually contains the hash code to create the required bucket index
	int getBucketIndex(string key)
	{
		int hashCode = 0;

		int currentCoeff = 1;
		for (int i = key.length(); i >= 0; i--)
		{
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;

			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets;
		}

		return hashCode % numBuckets;
	}

public:

	ourmap()
	{
		size = 0;
		numBuckets = 5;
		buckets = new MapNode<V> *[numBuckets];

		for (int i = 0; i < numBuckets; i++)
		{
			buckets[i] = NULL;
		}
	}

	~ourmap()
	{
		for (int i = 0; i < numBuckets; i++)
		{
			delete buckets[i];
		}

		delete[] buckets;
	}

	int size()
	{
		return count;
	}

	void insert(string key, V value)
	{
		int bucketIndex = getBucketIndex(key);

		MapNode<V>* head = buckets[bucketIndex];

		while (head != NULL)
		{
			if (head->key == key)
			{
				head->value = value;
				return;
			}

			head = head->next;
		}

		head = buckets[bucketIndex];
		MapNode<V>* newNode = new MapNode<V>(key, value);
		newNode->next = head;

		buckets[bucketIndex] = newNode;
		count++;
		return;
	}

	V remove(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* prev = NULL;

		while (head != NULL)
		{
			if (head->key == key)
			{
				if (prev == NULL)
				{
					buckets[bucketIndex] = head->next;
				}
				else
				{
					prev->next = head->next;
				}

				V value = head->value;
				head->next = NULL;
				delete head;
				count--;
			}

			prev = head;
			head = head->next;

			return value;

		}

		return 0; // signifies that the required value was not obtained i.e did not exist
	}

	V getValue(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];

		while (head != NULL)
		{
			if (head->key == key)
			{
				return head->value;
			}

			head = head->next;
		}

		return 0; // signifies that the required value was not obtained i.e did not exist

	}
};
