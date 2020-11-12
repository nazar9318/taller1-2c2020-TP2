#include "Lock.hpp"

Lock::Lock(std::mutex &mutex) : mutex(mutex) {
    this->mutex.lock();
}

Lock::~Lock() {
    this->mutex.unlock();
}