import requests
from requests.structures import CaseInsensitiveDict
import xml.etree.ElementTree as ET

url = "http://localhost:8080"

headers = CaseInsensitiveDict()
headers["Content-Type"] = "application/soap+xml"

data = """
<?xml version="1.0" encoding="UTF-8"?>
<SOAP-ENV:Envelope
    xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/"
    xmlns:SOAP-ENC="http://schemas.xmlsoap.org/soap/encoding/"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    xmlns:bhldr="http://tempuri.org/bhldr.xsd">
 <SOAP-ENV:Body>
  <bhldr:registerInfo>
   <inputInfo>
    <infoName>FT1</infoName>
    <value>59.9982</value>
    <timestamp>2021/02/20 01:00:12</timestamp>
    <dataType>ANALOG</dataType>
   </inputInfo>
   <inputInfo>
    <infoName>PT1</infoName>
    <value>490.21</value>
    <timestamp>2021/02/20 01:00:12</timestamp>
    <dataType>ANALOG</dataType>
   </inputInfo>
   <inputInfo>
    <infoName>FT1_QC</infoName>
    <value>9</value>
    <timestamp>2021/02/20 01:00:12</timestamp>
    <dataType>DIGITAL</dataType>
   </inputInfo>
   <inputInfo>
    <infoName>PT1_QC</infoName>
    <value>9</value>
    <timestamp>2021/02/20 01:00:12</timestamp>
    <dataType>DIGITAL</dataType>
   </inputInfo>
  </bhldr:registerInfo>
 </SOAP-ENV:Body>
</SOAP-ENV:Envelope>
"""

resp = requests.post(url, headers=headers, data=data)

root = ET.fromstring(resp.content)
# tree = ElementTree.fromstring(resp.content)
# for root in tree:
#     print(root.tag, root.attrib)
