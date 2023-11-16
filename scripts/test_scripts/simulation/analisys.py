#!/usr/bin/env python3
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np
import os, glob
from itertools import count

# Create a figure and axis
fig, ax = plt.subplots()
x_data = []
y_data = []

# Create an empty plot
line, = ax.plot([], [], label='Dynamic Data')

# Set the axes labels and title
ax.set_xlabel('Simulation time [s]')
ax.set_ylabel('Space consumed [KB]')
ax.set_title('Space allocation simulation [KB/s]')

file_path = "/home/cezario/beholder/"

def setSize(total_size):
    _KB = 1024
    if (total_size == 0):
        return 0
    return total_size/_KB

def get_size():
    total_size = 0
    for dirpath, dirnames, filenames in os.walk(file_path):
        for f in filenames:
            fp = os.path.join(dirpath, f)
            # skip if it is symbolic link
            if not os.path.islink(fp):
                total_size += os.path.getsize(fp)
    total_size = setSize(total_size)
    return total_size

# Add legend
ax.legend()

# Function to initialize the plot
def init():

    line.set_data([], [])
    return line,

# Function to update the plot data
def update(frame):
    # Add new data points
    x_data.append(frame)
    y_data.append(get_size())  # Replace this with your actual data

    # Update the plot with the new data
    line.set_data(x_data, y_data)

    # Adjust the plot limits if needed
    ax.relim()
    ax.autoscale_view()

    return line,

# Create an animation
animation = FuncAnimation(fig, update, frames=count(), init_func=init, blit=True, interval=1000)

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
