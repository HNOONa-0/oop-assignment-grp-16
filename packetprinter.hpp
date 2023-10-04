#ifndef _PACKET_PRINTER_HPP_
#define _PACKET_PRINTER_HPP_

#include"abstractpacket.hpp"
#include "rawpacket.hpp"
#include "ecpri.hpp"

class PacketPrinter{
    private:
        static int current_packet_num;

    public:
        void printPacketInfo(AbstractPacket* packet);
        void printPacketRawInfo(EthernetPacket* packet);
        void printPacketEcpriInfo(EthernetPacket_eCPRI* packet);
};

#endif