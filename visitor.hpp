#ifndef _VISITOR_HPP_
#define _VISITOR_HPP_

#include "rawpacket.hpp"
#include"ecpri.hpp"

class Visitor {
    public:
        virtual void visitRawEthernetPacket(EthernetPacket* packet) = 0;
        virtual void visitEcpriEthernetPacket(EthernetPacket_eCPRI* packet) = 0;
};

#endif