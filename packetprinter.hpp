#ifndef _PACKET_PRINTER_HPP_
#define _PACKET_PRINTER_HPP_

#include "rawpacket.hpp"
#include "ecpri.hpp"
#include "visitor.hpp"

class PacketPrinter: public Visitor{
    private:
        static int current_packet_num;

    public:
        void visitRawEthernetPacket(EthernetPacket* packet) override;
        void visitEcpriEthernetPacket(EthernetPacket_eCPRI* packet) override;
};

#endif