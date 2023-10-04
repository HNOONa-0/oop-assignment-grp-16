#ifndef _PACKET_HPP_
#define _PACKET_HPP_

#define MAX_ETHERNET_PACKET_SIZE_IN_BYTES   1526
#define ECPRI_TYPE_VALUE               "AEFE"

typedef struct PacketField{
    int sizeInBytes;
    std::string fieldData;
}PacketField;

class EthernetPacket {
    private:
        PacketField wholePacket;

        // packet fields in order
        PacketField preamble;
        PacketField destinationAddress;
        PacketField sourceAddress;
        PacketField type;
        PacketField payload;
        PacketField CRC;

    public:
        EthernetPacket();
        EthernetPacket(std::string& packetData);
        std::string getPreamble();
        std::string getDestinationAddress();
        std::string getSourceAddress();
        std::string getType();
        std::string getPayload();
        std::string getCRC();
        int is_eCPRI();
};



#endif