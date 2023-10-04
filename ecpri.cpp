#include<iostream>

#include"packet.hpp"
#include"ecpri.hpp"

static int get_LSB_from_str_hex(unsigned char hex){
// TODO: create a funciton that get the value of the LSB of a hex character

}

EthernetPacket_eCPRI::EthernetPacket_eCPRI(std::string& packetData) : EthernetPacket(packetData){
    int current_index = 0;

        // std::string protocolRevision;
        // std::string concatenationIndicator;
        // PacketField msgType;
        // PacketField payloadSize;
        // PacketField RtcId;
        // PacketField sequenceId;
        // PacketField realTimeCtrlData;

    protocolRevision = 

    preamble.sizeInBytes = 8;
    preamble.fieldData = wholePacket.fieldData.substr(current_index, preamble.sizeInBytes * 2);
    current_index += preamble.sizeInBytes * 2;
}

std::string EthernetPacket_eCPRI::getProtocolRevision(){

}

std::string EthernetPacket_eCPRI::getConcatenationIndicator(){

}

std::string EthernetPacket_eCPRI::getMassegeType(){

}

std::string EthernetPacket_eCPRI::getPayloadSize(){

}

std::string EthernetPacket_eCPRI::getRtcId(){

}

std::string EthernetPacket_eCPRI::getSequenceId(){

}

std::string EthernetPacket_eCPRI::getRealTimeCtrlData(){

}