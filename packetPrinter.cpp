#include<iostream>
#include "packet.hpp"
#include "ecpri.hpp"

using namespace std;

class PacketPrinter{
    private:
        static int current_packet_num;

    public:
        void printRawEthernetPacket(EthernetPacket& rawEthernetPacket){
            cout << "Packet # " << current_packet_num++ << ":" << endl;
            cout << rawEthernetPacket.getWholePacket() << endl;
            cout << "CRC: " << rawEthernetPacket.getCRC() << endl;
            cout << "Preamable: " << rawEthernetPacket.getPreamble() << endl;
            cout << "Destinationn Address: " << rawEthernetPacket.getDestinationAddress() << endl;
            cout << "Source Address: " << rawEthernetPacket.getSourceAddress() << endl;
            cout << "Type: " << rawEthernetPacket.getType() << endl;
            cout << "Payload: " << rawEthernetPacket.getPayload() << endl;
            cout << endl;
            cout << "***************************************************************************************" << endl;

        }

        void printECPRIPacket(EthernetPacket_eCPRI& eCPRI){
            cout << "Packet # " << current_packet_num++ << ":" << endl;
            cout << eCPRI.getWholePacket() << endl;
            cout << "CRC: " << eCPRI.getCRC() << endl;
            cout << "Concatenation Indicator: " << eCPRI.getConcatenationIndicator() << endl;
            cout << "Preamable: " << eCPRI.getPreamble() << endl;
            cout << "Destinationn Address: " << eCPRI.getDestinationAddress() << endl;
            cout << "Message Type: " << eCPRI.getMessageType() << endl;
            cout << "Payload Size: " << eCPRI.getPayloadSize() << endl;
            cout << "Protocol Version: " << eCPRI.getProtocolVersion() << endl;
            cout << "RTC ID: " << eCPRI.getRtcId() << endl;
            cout << "Sequence ID: " << eCPRI.getSequenceId() << endl;
            cout << "Source Address: " << eCPRI.getSourceAddress() << endl;
            cout << "Type: " << eCPRI.getType() << endl;
            cout << endl;
            cout << "***************************************************************************************" << endl;
            cout << endl;
        }
};