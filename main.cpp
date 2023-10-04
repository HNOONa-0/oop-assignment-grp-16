#include<iostream>

#include "abstractpacket.hpp"
#include "packetprinter.hpp"    

int main(){

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    std::string ethernetPacketLine;
    while(std::cin >> ethernetPacketLine){

        AbstractPacket* packet = AbstractPacket::createEthernetPacket(ethernetPacketLine);
        PacketPrinter printer;
        printer.printPacketInfo(packet);
        delete packet;
    }
}