
#include<iostream>

#include "abstractpacket.hpp"
#include "visitor.hpp"

#define MAX_ETHERNET_PACKET_SIZE_IN_BYTES   1526
#define ECPRI_TYPE_VALUE               "AEFE"

AbstractPacket::AbstractPacket(std::string& packetData) {
    try{
        if(packetData.size() % 2 == 1){
            throw "packet size is not correct";
        }
    }
    catch(std::string msg){
        std::cout << msg << std::endl;
    }

    wholePacket.sizeInBytes = packetData.size()/2;

    // size of the fields
    CRC.sizeInBytes = 4;
    preamble.sizeInBytes = 8;
    destinationAddress.sizeInBytes = 6;
    sourceAddress.sizeInBytes = 6;
    type.sizeInBytes = 2;
    wholePacket.fieldData = packetData;
    // we will use current index to correctly decide on the start of each field 
    int current_index = 0;

 
    preamble.fieldData = wholePacket.fieldData.substr(current_index, preamble.sizeInBytes * 2);
    current_index += preamble.sizeInBytes * 2;


    destinationAddress.fieldData = wholePacket.fieldData.substr(current_index, destinationAddress.sizeInBytes * 2);
    current_index += destinationAddress.sizeInBytes * 2;

    
    sourceAddress.fieldData = wholePacket.fieldData.substr(current_index, sourceAddress.sizeInBytes * 2);
    current_index += sourceAddress.sizeInBytes * 2;

    
    type.fieldData = wholePacket.fieldData.substr(current_index, type.sizeInBytes * 2);
    current_index += type.sizeInBytes * 2;

    // the packet size could change and so does the size of data field (defined here as payload)
    // this math correcly calculates the size of data field
    payload.sizeInBytes = wholePacket.sizeInBytes - type.sizeInBytes - sourceAddress.sizeInBytes 
        - destinationAddress.sizeInBytes - preamble.sizeInBytes - 4;
    payload.fieldData = wholePacket.fieldData.substr(current_index, payload.sizeInBytes * 2);
    current_index += payload.sizeInBytes * 2;

    CRC.fieldData = wholePacket.fieldData.substr(current_index, CRC.sizeInBytes * 2);

}
// getters for each field
std::string AbstractPacket::getPreamble(){
    return preamble.fieldData;
}

std::string AbstractPacket::getDestinationAddress(){
    return destinationAddress.fieldData;
}

std::string AbstractPacket::getSourceAddress(){
    return sourceAddress.fieldData;
}

std::string AbstractPacket::getType(){
    return type.fieldData;
}

std::string AbstractPacket::getPayload(){
    return payload.fieldData;
}

std::string AbstractPacket::getCRC(){
    return CRC.fieldData;
}

int AbstractPacket::is_eCPRI(){
    if(type.fieldData == std::string(ECPRI_TYPE_VALUE)){
        return true;
    }
    return false;
}

std::string AbstractPacket::getWholePacket() {
    return wholePacket.fieldData;
}

#include "rawpacket.hpp"
#include "ecpri.hpp"
// check type of packet and return corresponding packet
AbstractPacket* AbstractPacket::createEthernetPacket(std::string packetStr){
    if(packetStr.substr(40, 4) == ECPRI_TYPE_VALUE){
        return new EthernetPacket_eCPRI(packetStr);
    }
    return new EthernetPacket(packetStr);
}