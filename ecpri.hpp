#ifndef _ECPRI_HPP_
#define _ECPRI_HPP_

class EthernetPacket_eCPRI : public AbstractPacket {
    private:
        std::string protocolRevision;
        std::string concatenationIndicator;
        PacketField msgType;
        PacketField payloadSize;
        PacketField RtcId;
        PacketField sequenceId;
        PacketField realTimeCtrlData;

    public:
        EthernetPacket_eCPRI(std::string& packetData);
        std::string getProtocolVersion();
        std::string getConcatenationIndicator();
        std::string getMessageType();
        std::string getPayloadSize();
        std::string getRtcId();
        std::string getSequenceId();
        std::string getRealTimeCtrlData();

};

#endif