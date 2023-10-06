#include<iostream>
// include declrations of packet objects
#include "abstractpacket.hpp"
#include "packetprinter.hpp"

int main(){

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    std::string ethernetPacketLine;
    Visitor* printVisitor = new PacketPrinter();
    while(std::cin >> ethernetPacketLine){
        // pointer to correct sub-packet type to packet (polymorphism)
        AbstractPacket* packet = AbstractPacket::createEthernetPacket(ethernetPacketLine);
        // accept print visitor and print the 
        packet->accept(printVisitor);
        // free used memory
        delete packet;
    }
    // free used memory
    delete printVisitor;
}