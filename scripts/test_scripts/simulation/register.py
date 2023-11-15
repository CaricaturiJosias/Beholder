#!/usr/bin/python3
import requests
from datetime import datetime
from random import randrange
from time import sleep

headers = {
    'Content-Type': 'text/xml; charset=utf-8'
}

def generate_timestamp():
    now = datetime.now()
    return now.strftime('%Y/%m/%d %H:%M:%S')

def generate_default_payload():
    return """
<?xml version="1.0" encoding="UTF-8"?>
<SOAP-ENV:Envelope
    xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/"
    xmlns:SOAP-ENC="http://schemas.xmlsoap.org/soap/encoding/"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    xmlns:bhldr="http://tempuri.org/bhldr.xsd">
<SOAP-ENV:Body>
    <bhldr:registerInfo>"""

def end_payload(payload):
    return payload + \
"""</bhldr:registerInfo>
</SOAP-ENV:Body>
</SOAP-ENV:Envelope>"""

def add_request(current_request, name, value, isAnalog = False, scale = 0):
    if (isAnalog):
        type = "ANALOG"
        value = value + (randrange(-10,10, 1)*10**(scale+1))/10
        if (scale < 0):
            value = round(value, 3)
    else:
        type = "DIGITAL"
    # time = generate_timestamp()

    return current_request + \
f"""<inputInfo>
        <infoName>{name}</infoName>
        <value>{value}</value>
        <timestamp></timestamp>
        <dataType>{type}</dataType>
    </inputInfo>
    """ 

url = "http://localhost:12332"

# nome, escala, valor esperado
item_analog_list_n = [
    ['P',  700, True, 2],
    ['PF', 0.985, True, -2],
    ['F', 60, True, -2],
    ['Vv',  3110, True, 1],
    ['ED',  32505, True, 2],
    ['EPGen',  70, True, -1],
    ['EFGen', 0.1, True, -3],
    ['PFGen',  13, True, -1]
]

item_analog_list = [
    ['P', 3500, True, 2],
    ['PF', 0.98, True, -2],
    ['F', 60, True, -2],
    ['ED', 162525, True, 2],
    ['EPGen', 350, True, 1],
    ['EFGen', 0.2, True, -3],
    ['PFGen', 23, True, -1]
]

item_digital_list_n = [
    ['P_QC', 9, False, 0],
    ['F_QC', 9, False, 0],
    ['T', 9, False, 0],
    ['Area_', 9, False, 0]
]

def increment_payload_n(payload, items, n):
    if n == 0:
        number = ""
    else:
        number = str(n)

    for item in items:
        payload = \
            add_request(
                payload,
                (item[0] + number), \
                item[1], item[2], item[3])
    return payload

def simulationLoop():
    while (True):
        payload = generate_default_payload()

        for n in range(1,6):
            payload = increment_payload_n(payload, item_analog_list_n, n)
            payload = increment_payload_n(payload, item_digital_list_n, n)
        payload = increment_payload_n(payload, item_analog_list, 0)

        payload = end_payload(payload)
        try:
            response = requests.request("POST", url, headers=headers, data=payload)
            # if (response.ok) :
                # print("Requisição bem sucedida")
            if (not response.ok):
            # else :
                print(f"Response not ok: {response.status_code}")
                print(response.content)
        except Exception as e:
            print(f"Error: {e}")
        # print("\033c", end="")
        # print(payload)
        sleep(1/50)
    

def main():
    try:
        simulationLoop()
    except KeyboardInterrupt:
        print('Interrupted')

main()