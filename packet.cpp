

#include<iostream>
#include "packet.hpp"


EthernetPacket::EthernetPacket() {

}

EthernetPacket::EthernetPacket(std::string& packetData) {
    try{
        if(packetData.size() % 2 == 1){
            throw "packet size is not correct";
        }
    }
    catch(std::string msg){
        std::cout << msg << std::endl;
    }

    wholePacket.sizeInBytes = packetData.size()/2;
    wholePacket.fieldData = packetData;

    int current_index = 0;

    preamble.sizeInBytes = 8;
    preamble.fieldData = wholePacket.fieldData.substr(current_index, preamble.sizeInBytes * 2);
    current_index += preamble.sizeInBytes * 2;

    destinationAddress.sizeInBytes = 6;
    destinationAddress.fieldData = wholePacket.fieldData.substr(current_index, destinationAddress.sizeInBytes * 2);
    current_index += destinationAddress.sizeInBytes * 2;

    sourceAddress.sizeInBytes = 6;
    sourceAddress.fieldData = wholePacket.fieldData.substr(current_index, sourceAddress.sizeInBytes * 2);
    current_index += sourceAddress.sizeInBytes * 2;

    type.sizeInBytes = 2;
    type.fieldData = wholePacket.fieldData.substr(current_index, type.sizeInBytes * 2);
    current_index += type.sizeInBytes * 2;

    payload.sizeInBytes = wholePacket.sizeInBytes - type.sizeInBytes - sourceAddress.sizeInBytes 
        - destinationAddress.sizeInBytes - preamble.sizeInBytes - CRC.sizeInBytes;
    payload.fieldData = wholePacket.fieldData.substr(current_index, payload.sizeInBytes * 2);
    current_index += payload.sizeInBytes * 2;

    CRC.sizeInBytes = 4;
    CRC.fieldData = wholePacket.fieldData.substr(current_index, CRC.sizeInBytes * 2);

}

std::string EthernetPacket::getPreamble(){
    return preamble.fieldData;
}

std::string EthernetPacket::getDestinationAddress(){
    return destinationAddress.fieldData;
}

std::string EthernetPacket::getSourceAddress(){
    return sourceAddress.fieldData;
}

std::string EthernetPacket::getType(){
    return type.fieldData;
}

std::string EthernetPacket::getPayload(){
    return payload.fieldData;
}

std::string EthernetPacket::getCRC(){
    return CRC.fieldData;
}

int EthernetPacket::is_eCPRI(){
    if(type.fieldData == std::string(ECPRI_TYPE_VALUE)){
        return true;
    }
    return false;
}