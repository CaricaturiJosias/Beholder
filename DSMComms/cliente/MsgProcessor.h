//gsoap MsgProcessor service name:            MsgProcsessor Soap processor for Beholder
//gsoap MsgProcessor service protocol:        SOAP
//gsoap MsgProcessor service style:           document
//gsoap MsgProcessor service encoding:        encoded
//gsoap MsgProcessor service port:            http://beholder/Mist/endpoint/
//gsoap MsgProcessor service namespace:       http://beholder/Mist/MsgProcessor.wsdl
//gsoap MsgProcessor service location:        http://beholder/Mist/MsgProcessor.cgi

enum bhldr__DataType { UNKNOWN = 0, ANALOG = 1, DIGITAL = 2 };

struct bhldr__dataFormat {
    std::string  infoName; // required (Name to be translated with the ID maps)
    std::string  value; // required (Specific value to be saved depending on the dataType)
    std::string  timestamp; // optional (Timestamp of the sender, will be the machine local time if empty)
    enum bhldr__DataType dataType; // required (identifies the data type)
};

int bhldr__lookup(std::vector<std::string> infoId, std::vector<struct bhldr__dataFormat> &data);

int bhldr__registerInfo(std::vector<struct bhldr__dataFormat> inputInfo, bool &result);

int bhldr__updateInfo(std::vector<struct bhldr__dataFormat> message, void);
