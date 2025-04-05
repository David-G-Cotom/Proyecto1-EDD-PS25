//
// Created by Carlos Cotom on 21/03/2025.
//

#ifndef TRACK_H
#define TRACK_H

#include "Object.h"


class Track : public Object{

private:
    std::string type;
    int distance;

public:
    void setImage(std::string image) override;

    Track(std::string type, int distance);

    std::string getType();
    void setType(std::string type);

    int getDistance();
    void setDistance(int distance);

};



#endif //TRACK_H
