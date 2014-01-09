#include <iostream>
#include <string>
#include "NewsServer.h"

void listener1(int message) {
    cout << "Listener 1: " << message << endl;
}

void listener2(int message) {
    cout << "Listener 2: " << message << endl;
}

void listener3(int message) {
    cout << "Listener 3: " << message << endl;
}

int main (int argc, char** argv) {
    NewsServer<int> news;
    news.subscribe(listener1);
    news.subscribe(listener2);
    news += listener3;
    news.publish(53);
    news.publish(67);
}
