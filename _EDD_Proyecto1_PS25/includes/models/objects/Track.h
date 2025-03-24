//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef TRACK_H
#define TRACK_H

#include "Object.h"


class Track : public Object{

private:
    std::string type;

public:
    void setImage(std::string image) override;

    Track(std::string type);

    std::string getType();
    void setType(std::string type);

};



#endif //TRACK_H
