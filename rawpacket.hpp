#ifndef _PACKET_HPP_
#define _PACKET_HPP_

#include "abstractpacket.hpp"

class visitor;      //forward declaration to break the circular dependency

class EthernetPacket : public AbstractPacket {
    public:
        EthernetPacket(std::string packet);
        void accept(Visitor* visitor) override;
};



#endif