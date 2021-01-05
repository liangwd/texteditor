#ifndef SINGLETION_H
#define SINGLETION_H
#include <QMutex>
#include <QMutexLocker>

template<class T>
class Singletion
{
private:
    Singletion();

public:
    T* getInstance();
private:
    static T* sm_pInstance;
    static QMutex sm_Mutex;
};

#endif // SINGLETION_H
