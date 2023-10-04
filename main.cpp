#include<iostream>

#include "packet.hpp"
#include "ecpri.hpp"
#include "packetprinter.cpp"    

int PacketPrinter::current_packet_num = 0;

int main(){

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    std::string ethernetPacketLine;
    while(std::cin >> ethernetPacketLine){
        EthernetPacket ethernetPacket(ethernetPacketLine);
        PacketPrinter printer;

        printer.printRawEthernetPacket(ethernetPacket);

        std::cout<<std::endl;
    }
}