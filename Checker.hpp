#ifndef CHECKER_H
#define CHECKER_H

#include <mutex>
#include <string>
#include "Thread.hpp"
#include "DFSTree.hpp"
#include "FileStore.hpp"
#include "CheckStore.hpp"

class Checker : public Thread{
    private:
        FileStore &files;
        CheckStore &checks;
        void run() override;

    public:
        Checker(FileStore &files, CheckStore &checks);
        
        ~Checker();
};

#endif
