#ifndef HASHMAP_H
#define HASHMAP_H

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
            return const_cast<T*>(hm.find(key)); //converts the const T* to T*
        }
    private:
        //Helper functions
        unsigned int hash(std::string key);

        //member variables
        std::vector<std::list<std::pair<string, T>*>> m_buckets; //use a pointer for std::pair for effecient use of memory (dynamic allocation)
        unsigned long m_hashmap_size;
        double m_max_load;

};

#endif //HASHMAP_H