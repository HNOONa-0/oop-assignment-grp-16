#include<bits/stdc++.h>
#define len(v) (static_cast<int>(v.size() ) )

using namespace std;
class Packet{
public:
    string packet;
    int packetLength;

    const int preamableStart = 0, preamableSize = 8,
        preamableEnd = preamableStart + 2 * preamableSize;

    const int destinationAddressStart = preamableEnd, destinationAddressSize = 6,
        destinationAddressEnd = destinationAddressStart + 2 * destinationAddressSize;

    const int sourceAddressStart = destinationAddressEnd, sourceAddressSize = 6,
        sourceAddressEnd = sourceAddressStart + 2 * sourceAddressSize;

    const int typeStart=sourceAddressEnd, typeSize=2,
        typeEnd=typeStart+2 * typeSize;

    int dataStart = typeEnd, 
        dataSize, dataEnd;

    int fcsStart,
        fcsSize = 4, fcsEnd;

    Packet(string& _packet){
        this->packet=_packet;
        this->packetLength=_packet.size();
        // get fcs start and end, size is known
        this->fcsStart=(this->packetLength) - 2 * fcsSize;
        this->fcsEnd=this->packetLength;
        // get data size and end
        this->dataSize=(
            (this->packetLength) - 2 * (preamableSize
            + destinationAddressSize
            + sourceAddressSize
            + typeSize
            + fcsSize)
        ) / 2;
        // this->dataSize /= 2;

        this->dataEnd = this->dataStart + 2 * this->dataSize;
    }

    string getPreamable(){
        return packet.substr(preamableStart, 2 * preamableSize);
    }

    string getDestinationAddress(){
        return packet.substr(destinationAddressStart, 2 * destinationAddressSize);
    }

    string getSourceAddress(){
        return packet.substr(sourceAddressStart, 2 * sourceAddressSize);
    }

    string getType(){
        return packet.substr(typeStart, 2 * typeSize);
    }

    string getFcs(){
        return packet.substr(fcsStart, 2 * fcsSize);
    }

    string getData(){
        return packet.substr(dataStart,2 * dataSize);
    }
};
int main(){

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    string s;
    while(cin>>s){
        Packet p(s);

        cout<<p.getPreamable()<<endl;
        cout<<p.getDestinationAddress()<<endl;
        cout<<p.getSourceAddress()<<endl;
        cout<<p.getType()<<endl;
        cout<<p.getFcs()<<endl;
        cout<<p.getData()<<endl;
        
        cout<<endl;
    }
}