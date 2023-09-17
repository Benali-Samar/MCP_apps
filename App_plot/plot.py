#
#	Simple plot curve showing Temprature comming from the driver.
#


import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import time

# Initialize x and y data
x_data = [] # Time list
y_data = [] # Temperature values list

# Function to read temperature from the file and update the plot
def update_data(i):
    try:
        with open('/dev/mcp9808','r') as file:
            lines = file.readlines()
            temperature =  [int (line.strip())for line in lines]
            x_data.extend(range(len(y_data), len(y_data) + len(temperature))) # Use the loop counter as x-value
            y_data.extend(temperature)
            plt.cla()  # Clear the previous plot
            plt.plot(x_data, y_data, marker='o', c='g')
            plt.title("MCP9808 Temperature")
            plt.xlabel('Sample Number')
            plt.ylabel('Temperature (°C)')
    except ValueError:
            print(f"Skipping line {line.strip()}: Invalid format")
    except FileNotFoundError:
        print("File 'file.txt' not found!")
        exit()
# Create an animation that updates the plot every 1 second (1000 milliseconds)
ani = FuncAnimation(plt.gcf(), update_data, interval= 1000)

# Display the plot
plt.show()

