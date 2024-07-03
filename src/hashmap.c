#include "../include/hashmap.h"
#include <functional>

HashMap::HashMap(double max_load = 0.75) : m_hashmap_size(0), m_max_load(max_load) {}

void HashMap::insert(const std::string& key, const T& value_) {
    std::hash<std::strin> hash_function;

    size_t hashed_index = hash_function(key);

    m_buckets[hashed_index].push_back(std::make_pair(2, "world"));
}

