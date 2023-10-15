import paho.mqtt.client as mqtt

# Define MQTT parameters
broker_address = "localhost"
port = 1883  # Default MQTT port for RabbitMQ
topic = "mytopic"  # Use the same topic as in your RabbitMQ configuration

# Callback when a message is received
def on_message(client, userdata, message):
    print(f"Received message '{message.payload.decode()}' on topic '{message.topic}'")

# Create an MQTT client
client = mqtt.Client()

# Set the callback for when a message is received
client.on_message = on_message

# Connect to the broker
client.connect(broker_address, port=port)

# Subscribe to the MQTT topic
client.subscribe(topic)

# Start the MQTT client loop to listen for messages
client.loop_forever()
