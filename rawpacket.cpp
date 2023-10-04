

#include<iostream>

#include "abstractpacket.hpp"
#include"rawpacket.hpp"
#include "ecpri.hpp"


EthernetPacket::EthernetPacket(std::string packet) : AbstractPacket(packet){

}