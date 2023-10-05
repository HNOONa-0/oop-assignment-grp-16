#include<bits/stdc++.h>
#define len(v) (static_cast<int>(v.size() ) )

using namespace std;
map<string,int> hexMap={
        {"0", 0},
        {"1", 1},
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"A", 10},
        {"B", 11},
        {"C", 12},
        {"D", 13},
        {"E", 14},
        {"F", 15}
};
const int TYPE_START=40;

class PacketEthernet;
class PacketECPRI;
class Visitor{
public:
    virtual void visitPacketEthernet(PacketEthernet*) = 0;
    virtual void visitPacketECPRI(PacketECPRI*) = 0;
};
class Packet{
public:
    string packet;
    int packetLength;

    const int preambleStart = 0, preambleSize = 8,
        preambleEnd = preambleStart + 2 * preambleSize;
    string preamble;

    const int destinationAddressStart = preambleEnd, destinationAddressSize = 6,
        destinationAddressEnd = destinationAddressStart + 2 * destinationAddressSize;
    string destinationAddress;

    const int sourceAddressStart = destinationAddressEnd, sourceAddressSize = 6,
        sourceAddressEnd = sourceAddressStart + 2 * sourceAddressSize;
    string sourceAddress;
    
    const int typeStart=sourceAddressEnd, typeSize=2,
        typeEnd=typeStart+2 * typeSize;
    string type;

    int dataStart = typeEnd, 
        dataSize, dataEnd;
    string data;

    int fcsStart,
        fcsSize = 4, fcsEnd;
    string fcs;

    Packet(string& _packet){
        this->packet=_packet;
        this->packetLength=_packet.size();
        // get fcs start and end, size is known
        this->fcsStart=(this->packetLength) - 2 * fcsSize;
        this->fcsEnd=this->packetLength;
        // get data size and end
        this->dataSize=(
            (this->packetLength) - 2 * (preambleSize
            + destinationAddressSize
            + sourceAddressSize
            + typeSize
            + fcsSize)
        ) / 2;
        // this->dataSize /= 2;
        this->dataEnd = this->dataStart + 2 * this->dataSize;

        preamble=clcString(packet, preambleStart, preambleSize);
        destinationAddress = clcString(packet, destinationAddressStart, destinationAddressSize);
        sourceAddress = clcString(packet, sourceAddressStart, sourceAddressSize);
        type = clcString(packet, typeStart, typeSize);
        data = clcString(packet, dataStart, dataSize);
        fcs = clcString(packet, fcsStart, fcsSize);
    }
    string clcString(string& s,int a,int b){
        return s.substr(a, 2 * b);
    }
    string getPacket(){
        return packet;
    }
    string getPreamble() {
        return preamble;
    }

    string getDestinationAddress() {
        return destinationAddress;
    }

    string getSourceAddress() {
        return sourceAddress;
    }

    string getType() {
        return type;
    }

    string getFcs() {
        return fcs;
    }

    string getData() {
        return data;
    }
    virtual void accept(Visitor* visitor) = 0;
};
class PacketECPRI : public Packet{
    
    public:
        const int protocolStart=0, protocolSize=1, protocolEnd=protocolStart+2*protocolSize;
        string protocol;

        const int messageTypeStart=protocolEnd, messageTypeSize=1, messageTypeEnd=messageTypeStart+2*messageTypeSize;
        string messageType;

        const int payloadSizeStart=messageTypeEnd, payloadSizeSize=2, payloadSizeEnd=payloadSizeStart+2*payloadSizeSize;
        string payloadSize;

        const int rtcIdStart=payloadSizeEnd, rtcIdSize=2, rtcIdEnd=rtcIdStart+2*rtcIdSize;
        string rtcId;
        
        const int seqIdStart=rtcIdEnd, seqIdSize=2, seqIdEnd=rtcIdStart+2*seqIdSize;
        string seqId;
        PacketECPRI(string& _packet): Packet(_packet){
            protocol = clcString(data, protocolStart, protocolSize);
            messageType = clcString(data, messageTypeStart, messageTypeSize);
            payloadSize = clcString(data, payloadSizeStart, payloadSizeSize);
            rtcId = clcString(data, rtcIdStart, rtcIdSize);
            seqId = clcString(data, seqIdStart, seqIdSize);
        }
        string getProtocolRevision() {
            return string(1,protocol[0]);
        }
        string getProtocolReserved() {
            return string(1,protocol[1]);
        }
        string getMessageType() {
            return messageType;
        }

        string getPayloadSize() {
            return payloadSize;
        }

        string getRtcId() {
            return rtcId;
        }

        string getSeqId(){
            return seqId;
        }
        string getConcatenationIndicator(){
            int k=(hexMap[string(protocol[1], 1) ]&1);
            return string(1, static_cast<char>('0'+k));
        }
        virtual void accept(Visitor* visitor) override{
            visitor->visitPacketECPRI(this);
        }

};
class PacketEthernet : public Packet{
    public:
        PacketEthernet(string& _packet): Packet(_packet){
        }
    // might have some methods
    virtual void accept(Visitor* visitor) override{
        visitor->visitPacketEthernet(this);
    }
};
class PrintVisitor: public Visitor{
    static int current_packet_num;
    void visitPacketEthernet(PacketEthernet* p){
        PacketEthernet rawEthernetPacket=*p;
        cout << "Packet # " << current_packet_num++ << ":" << endl;
        cout << rawEthernetPacket.getPacket() << endl;
        cout << "CRC: " << rawEthernetPacket.getFcs() << endl;
        cout << "Destinationn Address: " << rawEthernetPacket.getDestinationAddress() << endl;
        cout << "Source Address: " << rawEthernetPacket.getSourceAddress() << endl;
        // cout << "Data: "<< rawEthernetPacket.getData() << endl;
        cout << "Type: " << rawEthernetPacket.getType() << endl;
        cout << "**************************************************************************************************************************************************************************************************************************************" << endl;
        cout<<endl;
    }
    void visitPacketECPRI(PacketECPRI* p){
        PacketECPRI eCPRI=*p;
        cout << "Packet # " << current_packet_num++ << ":" << endl;
        cout << eCPRI.getPacket() << endl;
        cout << "CRC: " << eCPRI.getFcs() << endl;
        cout << "Concatenation Indicator: " << eCPRI.getConcatenationIndicator() << endl;
        cout << "Destination Address: " << eCPRI.getDestinationAddress() << endl;
        // cout << "Preamble: " << eCPRI.getPreamble() << endl;
        cout << "Message Type: " << eCPRI.getMessageType() << endl;
        cout << "Payload Size: " << eCPRI.getPayloadSize() << endl;
        cout << "Protocol Version: " << eCPRI.getProtocolRevision() << endl;
        cout << "RTC ID: " << eCPRI.getRtcId() << endl;
        cout << "Sequence ID: " << eCPRI.getSeqId() << endl;
        cout << "Source Address: " << eCPRI.getSourceAddress() << endl;
        cout << "Type: " << eCPRI.getType() << endl;
        cout << endl;
        cout << "**************************************************************************************************************************************************************************************************************************************" << endl;
        cout << endl;
    }
};
Packet* init(string& s){
    string t = s.substr(TYPE_START,4);
    if(t=="AEFE") return new PacketECPRI(s);
    return new PacketEthernet(s);
}
int PacketPrinter::current_packet_num=0;
int PrintVisitor::current_packet_num=0;
int main(){

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    string s;
    Visitor* visitor=new PrintVisitor();
    while(cin>>s){
        Packet* org=init(s);
        org->accept(visitor);
    }
}