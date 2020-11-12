#ifndef LOCK_H
#define LOCK_H

#include <mutex>

class Lock {
    private:
        std::mutex &mutex;
        Lock(const Lock&) = delete;
        Lock& operator=(const Lock&) = delete;
        Lock(Lock&&) = delete;
        Lock& operator=(const Lock&&) = delete;
    public:
        Lock(std::mutex &mutex);
        ~Lock();
};

#endif
