#ifndef _PACKET_HPP_
#define _PACKET_HPP_





class EthernetPacket : public AbstractPacket {
    public:
        EthernetPacket(std::string packet);
};



#endif