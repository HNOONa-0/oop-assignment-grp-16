#ifndef _ABSTRACT_PACKET_H_
#define _ABSTRACT_PACKET_H_

typedef struct PacketField{
    int sizeInBytes;
    std::string fieldData;
}PacketField;

class AbstractPacket {
    protected:
        PacketField wholePacket;

        // packet fields in order
        PacketField preamble;
        PacketField destinationAddress;
        PacketField sourceAddress;
        PacketField type;
        PacketField payload;
        PacketField CRC;
        

    public:
        AbstractPacket(std::string& packetData);
        virtual std::string getWholePacket();
        virtual std::string getPreamble();
        virtual std::string getDestinationAddress();
        virtual std::string getSourceAddress();
        virtual std::string getType();
        virtual std::string getPayload();
        virtual std::string getCRC();
        virtual int is_eCPRI();
        static AbstractPacket* createEthernetPacket(std::string packetStr);
};


#endif