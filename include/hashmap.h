#ifndef HASHMAP_H
#define HASHMAP_H

#include <functional>
#include <vector>
#include <list>
#include <utility> 
#include <string>

//DELETE LATER
#include <iostream>

template <typename T> 
class HashMap
{
    public:
        HashMap(double max_load = 0.75);

        ~HashMap();

        inline unsigned long size() const { return m_items; }

        void insert(const std::string& key, const T& value);

        T& operator[](const std::string& key);

        const T* find(const std::string& key) const;

        T* find(const std::string& key) {
            const auto& hm = *this;
            return const_cast<T*>(hm.find(key));
        }
    private:
        //Delete copy constructor/assignment operator bc hashmaps have no need for them
        HashMap(const HashMap&) = delete;
        HashMap& operator=(const HashMap&) = delete;

        //Helper functions
        unsigned int hash(std::string key, size_t size) const;
        void rehash();

        //Member variables
        std::vector<std::list<std::pair<std::string, T>*>> m_buckets; 
        unsigned long m_items;
        double m_max_load;

};

template<typename T>
HashMap<T>::HashMap(double max_load) 
: m_items(0), m_max_load(max_load), m_buckets(10) 
{}

template<typename T>
HashMap<T>::~HashMap() {
    for (auto vec_it = m_buckets.begin(); vec_it != m_buckets.end(); vec_it++) {
        for (auto list_it = vec_it->begin(); list_it != vec_it->end(); list_it++) {
            delete *list_it;
        }
    }
}

template<typename T>
void HashMap<T>::insert(const std::string& key, const T& value) {
    if (!find(key)) { //If key DOES NOT exist within the hashmap
        size_t hashed_index = hash(key, m_buckets.size());
        std::pair<std::string, T>* new_pair = new std::pair<std::string, T>(key, value);
        m_buckets[hashed_index].push_back(new_pair);
        m_items++;
    }
    else {
        T* old_value = find(key); //calls the non-const version of find
        *old_value = value;
    }
    
    if (static_cast<float>(m_items) / m_buckets.size() >= m_max_load) {
        rehash();
    }
}

template<typename T>
T& HashMap<T>::operator[](const std::string& key) {
    return (find(key)) ? *find(key) : nullptr; 
} 

template<typename T>
const T* HashMap<T>::find(const std::string& key) const {
    //hash the string key to a index
    size_t hashed_index = hash(key, m_buckets.size());

    auto linked_list = m_buckets[hashed_index];
    
    for (auto it = linked_list.begin(); it != linked_list.end(); it++) {
        //If the key's match, return the iterator (a reference to the class)
        if (((*it)->first) == key) { //Dereferencing it provides a pointer to a pair
            return &(*it)->second;
        } 
    }
    return nullptr;
}

template<typename T>
unsigned int HashMap<T>::hash(std::string key, size_t size) const {
    std::hash<std::string> hash_function;
    size_t hashed_index = hash_function(key);
    //mod the index by the bucket size to ensure a valid index
    hashed_index %= size;
    return hashed_index;
}  

template<typename T>
void HashMap<T>::rehash() {
    std::vector<std::list<std::pair<std::string, T>*>> rehashed_buckets(m_buckets.size() * 2);

    for (auto& vector_it : m_buckets) {
        for (auto& list_it : vector_it) {
            std::string key = list_it->first;
            size_t rehashed_index = hash(key, rehashed_buckets.size());
            rehashed_buckets[rehashed_index].push_back(list_it);
        }
    }

    m_buckets = rehashed_buckets;
}

#endif //HASHMAP_H