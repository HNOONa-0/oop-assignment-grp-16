#ifndef _VISITOR_HPP_
#define _VISITOR_HPP_

#include "rawpacket.hpp"
#include"ecpri.hpp"
// the visitor interface
// later we will use it to declare PrintVisitor exclusively for printing the packets
class Visitor {
    public:
        virtual void visitRawEthernetPacket(EthernetPacket* packet) = 0;
        virtual void visitEcpriEthernetPacket(EthernetPacket_eCPRI* packet) = 0;
};

#endif