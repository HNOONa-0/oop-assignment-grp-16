#include<iostream>

#include "helpers.hpp"
#include"ecpri.hpp"
#include "visitor.hpp"

static std::string get_LSB_from_str_hex(unsigned char hex){
// TODO: create a funciton that get the value of the LSB of a hex character
    return std::string();
}

EthernetPacket_eCPRI::EthernetPacket_eCPRI(std::string& packetData) : AbstractPacket(packetData){
    int current_index = 0;

    protocolRevision = payload.fieldData[current_index++];
    concatenationIndicator = get_LSB_from_str_hex(payload.fieldData[current_index++]);

    msgType.sizeInBytes = 1;
    msgType.fieldData = payload.fieldData.substr(current_index, msgType.sizeInBytes * 2);
    current_index += msgType.sizeInBytes * 2;

    payloadSize.sizeInBytes = 2;
    payloadSize.fieldData = payload.fieldData.substr(current_index, payloadSize.sizeInBytes * 2);
    current_index += payloadSize.sizeInBytes * 2;

    RtcId.sizeInBytes = 2;
    RtcId.fieldData = payload.fieldData.substr(current_index, RtcId.sizeInBytes * 2);
    current_index += RtcId.sizeInBytes * 2;

    sequenceId.sizeInBytes = 2;
    sequenceId.fieldData = payload.fieldData.substr(current_index, sequenceId.sizeInBytes * 2);
    current_index += sequenceId.sizeInBytes * 2;

    realTimeCtrlData.sizeInBytes = payload.sizeInBytes - 8;
    realTimeCtrlData.fieldData = payload.fieldData.substr(current_index, realTimeCtrlData.sizeInBytes * 2);

}

std::string EthernetPacket_eCPRI::getProtocolVersion(){
    return protocolRevision;
}

std::string EthernetPacket_eCPRI::getConcatenationIndicator(){
    return concatenationIndicator;
}

std::string EthernetPacket_eCPRI::getMessageType(){
    return msgType.fieldData;
}

std::string EthernetPacket_eCPRI::getPayloadSize(){
    return payloadSize.fieldData;
}

std::string EthernetPacket_eCPRI::getRtcId(){
    return RtcId.fieldData;
}

std::string EthernetPacket_eCPRI::getSequenceId(){
    return sequenceId.fieldData;
}

std::string EthernetPacket_eCPRI::getRealTimeCtrlData(){
    return realTimeCtrlData.fieldData;
}

void EthernetPacket_eCPRI::accept(Visitor* visitor) {
    visitor->visitEcpriEthernetPacket(this);
}