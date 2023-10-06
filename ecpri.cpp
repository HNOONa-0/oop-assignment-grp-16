#include<iostream>
#include<map>

#include "helpers.hpp"
#include"ecpri.hpp"
#include "visitor.hpp"


EthernetPacket_eCPRI::EthernetPacket_eCPRI(std::string& packetData) : AbstractPacket(packetData){
    // current index will decide the start of each field in the packet string
    // so we can parse the string into fields
    int current_index = 0;
    // below we correctly intialize each field
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
// getters of each field
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
// visitor pattern related logic
void EthernetPacket_eCPRI::accept(Visitor* visitor) {
    visitor->visitEcpriEthernetPacket(this);
}