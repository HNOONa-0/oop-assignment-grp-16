#ifndef _PACKET_PRINTER_HPP_
#define _PACKET_PRINTER_HPP_

#include "rawpacket.hpp"
#include "ecpri.hpp"
#include "visitor.hpp"
// PacketPrinter is a type of concrete visitor inherts from visitor
// which is responsible for printing the packets
class PacketPrinter: public Visitor{
    private:
        static int current_packet_num;

    public:
        // these methods will be overridden by PacketPrinter
        void visitRawEthernetPacket(EthernetPacket* packet) override;
        void visitEcpriEthernetPacket(EthernetPacket_eCPRI* packet) override;
};

#endif