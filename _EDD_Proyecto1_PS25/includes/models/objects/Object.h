//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef OBJECT_H
#define OBJECT_H
#include <string>


class Object {

public:
    std::string image;

    virtual ~Object() = default;

    virtual void setImage(std::string image) = 0;

};



#endif //OBJECT_H
