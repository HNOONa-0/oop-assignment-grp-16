

#include<iostream>

#include "rawpacket.hpp"
#include "visitor.hpp"


EthernetPacket::EthernetPacket(std::string packet) : AbstractPacket(packet){

}

void EthernetPacket::accept(Visitor* visitor) {
    visitor->visitRawEthernetPacket(this);
}