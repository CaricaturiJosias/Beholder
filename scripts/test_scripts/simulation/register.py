#!/usr/bin/python3
from matplotlib.animation import FuncAnimation
import requests, os, glob, time
import matplotlib.pyplot as plt
from datetime import datetime
from random import randrange
import numpy as np
from itertools import count

# Create a figure and axis
fig, ax = plt.subplots()
x_data = []
y_data = []

# Create an empty plot
line, = ax.plot([], [], label='Dynamic Data')

# Set the axes labels and title
ax.set_xlabel('Request number [-]')
ax.set_ylabel('Time consumed per request [s]')
ax.set_title('Time consumed per request sent')

file_path = "/home/cezario/beholder/"

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

url = "http://172.25.159.16:12332"

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

def init():
    line.set_data([], [])
    return line,


def update(frame):
    # Add new data points
    x_data.append(frame)
    y_data.append(simulationLoop())  # Replace this with your actual data

    # Update the plot with the new data
    line.set_data(x_data, y_data)

    # Adjust the plot limits if needed
    ax.relim()
    ax.autoscale_view()

    return line,

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
    payload = generate_default_payload()

    for n in range(1,6):
        payload = increment_payload_n(payload, item_analog_list_n, n)
        payload = increment_payload_n(payload, item_digital_list_n, n)
    payload = increment_payload_n(payload, item_analog_list, 0)

    payload = end_payload(payload)
    try:
        start_time = time.perf_counter()
        response = requests.request("POST", url, headers=headers, data=payload)
        end_time = time.perf_counter()
        if (response.ok) :
            return end_time - start_time
        else:
            print(f"Response not ok: {response.status_code}")
            print(response.content)
            return 0

    except Exception as e:
        print(f"Error: {e}")
        return 0
    # print("\033c", end="")
    # print(payload)

animation = FuncAnimation(fig, update, frames=count(), init_func=init, blit=True, interval=1000/20)

# Set up a signal handler for Ctrl+C
import signal
def keyboard_interrupt_handler(signum, frame):
    try:
        files_to_delete = glob.glob(os.path.join(file_path, '*'))
        for file_path_item in files_to_delete:
            if os.path.isfile(file_path_item):
                os.remove(file_path_item)
        print("All files deleted successfully.")
        quit()
    except Exception as e:
        print(f"An error occurred: {e}")

signal.signal(signal.SIGINT, keyboard_interrupt_handler)

# Show the plot
plt.show()
