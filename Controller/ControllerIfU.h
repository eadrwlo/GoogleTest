//
// Created by me on 10.01.2020.
//

#ifndef GOOGLETESTREPO_CONTROLLERIFU_H
#define GOOGLETESTREPO_CONTROLLERIFU_H

class ControllerIfU {
public:
    virtual ~ControllerIfU() {};
    virtual bool isAllowedAscending(int i) const = 0;
    virtual bool isAllowedToPrint() const = 0;
    virtual void printA(int i) const = 0;
};


#endif //GOOGLETESTREPO_CONTROLLERIFU_H
