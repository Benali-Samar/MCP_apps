import pika

# Define your AMQP server connection parameters
connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

    # Declare the queue you want to publish to
#queue_name = 'test.queue'
#channel.queue_declare(queue=queue_name, durable=True)

#ublish a message to the queue
message = "Hello !"
channel.basic_publish(exchange='test.exchange', routing_key='detection', body=message)

#print(f"Sent '{message}' to {queue_name}")

    # Close the connection
connection.close()


