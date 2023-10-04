#include<iostream>

#include "packet.hpp"

int main(){

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    std::string ethernetPacketLine;
    while(std::cin >> ethernetPacketLine){
        EthernetPacket ethernetPacket(ethernetPacketLine);

        std::cout<<ethernetPacketLine<<std::endl;
        std::cout<<ethernetPacket.getPreamble()<<std::endl;
        std::cout<<ethernetPacket.getDestinationAddress()<<std::endl;
        std::cout<<ethernetPacket.getSourceAddress()<<std::endl;
        std::cout<<ethernetPacket.getType()<<std::endl;
        std::cout<<ethernetPacket.getPayload()<<std::endl;
        std::cout<<ethernetPacket.getCRC()<<std::endl;
        
        std::cout<<std::endl;
    }
}