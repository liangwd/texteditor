#include "singletion.h"

template<class T>
T* Singletion<T>::sm_pInstance = nullptr;

template<class T>
QMutex Singletion<T>::sm_Mutex;

template<class T>
Singletion<T>::Singletion()
{

}

template<class T>
T *Singletion<T>::getInstance()
{
    if(nullptr == sm_pInstance)
    {
        QMutexLocker locker(&sm_Mutex);
        if(nullptr == sm_pInstance){
            sm_pInstance = new T;
        }
    }

    return sm_pInstance;
}
