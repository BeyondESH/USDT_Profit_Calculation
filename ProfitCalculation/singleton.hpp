#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <QObject>

template<class T>
class Singleton :public QObject{
public:
    static T& getInstance(){
        static T instance;
        return instance;
    }
protected:
    Singleton(){}
    Singleton(const Singleton<T>&)=delete;
    Singleton& operator=(const Singleton<T>&)=delete;
};
#endif // SINGLETON_HPP
