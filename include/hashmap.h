#ifndef HASHMAP_H
#define HASHMAP_H

#include <functional>
#include <vector>
#include <list>
#include <utility> 
#include <string>

template <typename T> 
class HashMap
{
    public:
        HashMap(double max_load = 0.75);

        ~HashMap() = default;

        inline unsigned long size() const { return m_hashmap_size; }

        void insert(const std::string& key, const T& value);

        T& operator[](const std::string& key);

        const T* find(const std::string& key) const;

        T* find(const std::string& key) { //non const version of find
            const auto& hm = this;
            return const_cast<T*>(hm->find(key)); //converts the const T* to T*
        }
    private:
        //Delete copy constructor/assignment operator bc hashmaps have no need for them
        HashMap(const HashMap&) = delete;
        HashMap& operator=(const HashMap&) = delete;

        //Helper functions
        unsigned int hash(std::string key) const;

        //Member variables
        std::vector<std::list<std::pair<std::string, T>>> m_buckets; //use a pointer for std::pair for effecient use of memory (dynamic allocation)
        unsigned long m_hashmap_size;
        double m_max_load;

};

template<typename T>
HashMap<T>::HashMap(double max_load) 
: m_hashmap_size(0), m_max_load(max_load), m_buckets(10) 
{}

template<typename T>
void HashMap<T>::insert(const std::string& key, const T& value) {
    m_hashmap_size++;
    
    //If load factor exceeded, rehash buckets
    size_t hashed_index = hash(key);
    
    std::pair<std::string, T> new_pair = std::pair<std::string, T>(key, value);

    m_buckets[hashed_index].push_back(new_pair);
}

template<typename T>
T& HashMap<T>::operator[](const std::string& key) {
    return (find(key)) ? *find(key) : nullptr; 
} 

template<typename T>
const T* HashMap<T>::find(const std::string& key) const {
    //hash the string key to a index
    size_t hashed_index = hash(key);

    auto linked_list = m_buckets[hashed_index];
    
    return m_buckets[hashed_index].front().first;
    // //iterate through the linked list and search for the correct node
    // for (auto it = linked_list.begin(); it != linked_list.end(); it++) {
    //     //if the key's match, return the iterator (a reference to the class)
    //     if (((*it).first) == key) {
    //         return it;
    //     } 
    // }
    // return nullptr;
}

template<typename T>
unsigned int HashMap<T>::hash(std::string key) const {
    std::hash<std::string> hash_function;
    size_t hashed_index = hash_function(key);
    //mod the index by the bucket size to ensure a valid index
    hashed_index %= m_buckets.size();
    return hashed_index;
} 

#endif //HASHMAP_H