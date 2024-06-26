#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <list>
#include <utility> 

template <typename T> 
class HashMap
{
    public:
        HashMap(double max_load = 0.75);

        ~HashMap();

        inline unsigned long size() const { return m_hashmap_size; }

        void insert(const std::string& key, const T& value);

        T& operator[](const std::string& key);

        const T* find(const std::string& key) const;

        T* find(const std::string& key) {
            const auto& hm = this;
            return const_cast<T*>(hm.find(key));
        }
    private:
        std::vector<std::list<std::pair<string, T>>> m_buckets;
        unsigned long m_hashmap_size;


};

#endif //HASHMAP_H