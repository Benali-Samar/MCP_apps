import paho.mqtt.client as mqtt

# This is the Publisher
topic = "mytopic"

message = "rabbit queue"

client = mqtt.Client()
client.connect("localhost",1884,60)
client.publish(topic, payload=message);
client.disconnect();
print("Message published to the queue successfully!")
