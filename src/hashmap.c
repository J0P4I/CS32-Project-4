#include "../include/hashmap.h"
#include <functional>

HashMap::HashMap(double max_load = 0.75) : m_hashmap_size(0), m_max_load(max_load), m_buckets(10) {
}

void HashMap::insert(const std::string& key, const T& value_) {
    m_hashmap_size++;
    
    size_t hashed_index = hash(key);
    
    std::pair<std::string, T>* current_pair = new std::pair<std::string, T>(key, value);

    m_buckets[hashed_index].push_back(current_pair);


}

T& HashMap::operator[](const std::string& key) {
    if (find(key)) {
        return find(key);
    }
    return nullptr;
} 

const T* find(const std::string& key) const {
    std::hash<std::string> hash_function;

    size_t hashed_index = hash(key);

    if (m_buckets[hashed_index] != nullptr) {
        return *m_buckets[hashed_index];
    }
}
unsigned int HashMap::hash(std::string key) {
    std::hash<std::string> hash_function;

    size_t hashed_index = hash_function(key);

    return hashed_index;
}
}




