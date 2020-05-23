//
// Created by Ricardo Nunes on 20/05/2020.
//

#ifndef CODE_VERTICENOTFOUND_H
#define CODE_VERTICENOTFOUND_H

template <class T>
class VerticeNotFound {
    T info;
public:
    VerticeNotFound(T info) : info(info) {}

    T getInfo() const {
        return info;
    }
};


#endif //CODE_VERTICENOTFOUND_H
