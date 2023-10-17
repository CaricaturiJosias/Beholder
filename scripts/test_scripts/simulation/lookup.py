#!/usr/bin/python3
import requests

url = "http://localhost:8080"

request_data = {
    'infoId': 'FT1',
    'dataType': 'ANALOG',
    'timestamp': '2021/02/20 01:00:12'
}
# SOAP request URL
 
# structured XML
payload = """
<?xml version="1.0" encoding="UTF-8"?>
<SOAP-ENV:Envelope
    xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/"
    xmlns:SOAP-ENC="http://schemas.xmlsoap.org/soap/encoding/"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    xmlns:bhldr="http://tempuri.org/bhldr.xsd">
 <SOAP-ENV:Body>
  <bhldr:lookup>
   <infoId>FT1</infoId>
   <dataType>ANALOG</dataType>
   <timestamp></timestamp>
  </bhldr:lookup>
 </SOAP-ENV:Body>
</SOAP-ENV:Envelope>
"""

# headers
headers = {
    'Content-Type': 'text/xml; charset=utf-8'
}
# POST request
response = requests.request("POST", url, headers=headers, data=payload)
 
# prints the response
print(response.text)
print(response)
