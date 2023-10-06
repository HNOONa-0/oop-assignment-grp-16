#include<iostream>

#include "abstractpacket.hpp"
#include "packetprinter.hpp"

int main(){

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    std::string ethernetPacketLine;
    Visitor* printVisitor = new PacketPrinter();
    while(std::cin >> ethernetPacketLine){

        AbstractPacket* packet = AbstractPacket::createEthernetPacket(ethernetPacketLine);
        packet->accept(printVisitor);
        delete packet;
    }
    delete printVisitor;
}