#ifndef NEWSSERVER_H
#define NEWSSERVER_H

#include <set>

using namespace std;

template <typename T>
class NewsServer {
    private:
        set<void (*)(T)> subscribers;
    
    public:
        void subscribe(void (*notify)(T));
        void publish(const T& message);
        NewsServer<T>& operator+= (void (*notify)(T));
};

template <typename T>
void NewsServer<T>::subscribe(void (*notify)(T)) {
    subscribers.insert(notify);
}

template <typename T>
void NewsServer<T>::publish(const T& message) {
    typename set<void (*)(T)>::iterator iter;
    for (iter = subscribers.begin(); iter != subscribers.end(); ++iter) {
        (*iter)(message);
    }
}

template <typename T>
NewsServer<T>& NewsServer<T>::operator+= (void (*notify)(T)) {
    subscribe(notify);
}

#endif
