#include<iostream>

#include "packetprinter.hpp"

using namespace std;

int PacketPrinter::current_packet_num = 0;


void PacketPrinter::visitRawEthernetPacket(EthernetPacket* packet){
    cout << "Packet # " << current_packet_num++ << ":" << endl;
    cout << packet->getWholePacket() << endl;
    cout << "CRC: " << packet->getCRC() << endl;
    cout << "Destination Address: " << packet->getDestinationAddress() << endl;
    cout << "Source Address: " << packet->getSourceAddress() << endl;
    cout << "Type: " << packet->getType() << endl;
    cout << "Payload: " << packet->getPayload() << endl;
    cout << endl;
    cout << "***************************************************************************************" << endl;
    cout << endl;
}

void PacketPrinter::visitEcpriEthernetPacket(EthernetPacket_eCPRI* packet){
    cout << "Packet # " << current_packet_num++ << ":" << endl;
    cout << packet->getWholePacket() << endl;
    cout << "CRC: " << packet->getCRC() << endl;
    cout << "Concatenation Indicator: " << packet->getConcatenationIndicator() << endl;
    cout << "Destination Address: " << packet->getDestinationAddress() << endl;
    cout << "Message Type: " << packet->getMessageType() << endl;
    cout << "Payload Size: " << packet->getPayloadSize() << endl;
    cout << "Protocol Version: " << packet->getProtocolVersion() << endl;
    cout << "RTC ID: " << packet->getRtcId() << endl;
    cout << "Sequence ID: " << packet->getSequenceId() << endl;
    cout << "Source Address: " << packet->getSourceAddress() << endl;
    cout << "Type: " << packet->getType() << endl;
    cout << endl;
    cout << "***************************************************************************************" << endl;
    cout << endl;
}