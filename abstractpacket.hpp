#ifndef _ABSTRACT_PACKET_H_
#define _ABSTRACT_PACKET_H_
// declare visitor so AbstractPacket can use it
class Visitor;
typedef struct PacketField{
    int sizeInBytes;
    std::string fieldData;
}PacketField;

class AbstractPacket {
    protected:
        PacketField wholePacket;

        // packet fields in order
        // contains fields common to both ecpri and rawEthernet
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
        virtual void accept(Visitor* visitor) = 0;

        static AbstractPacket* createEthernetPacket(std::string packetStr);
};


#endif