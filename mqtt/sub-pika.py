import pika

def callback(ch, method, properties, body):
    # Callback function to handle incoming messages
    print(f"Received message: {body}")

# Define your AMQP server connection parameters
connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

# Declare the queue to consume messages from
#queue_name = 'myqueu'
#channel.queue_declare(queue=queue_name, durable=True)

# Set up a consumer with the callback function
channel.basic_consume(queue="test.queue", on_message_callback=callback, auto_ack=True)

print('Waiting for messages. To exit, press CTRL+C')

# Start consuming
channel.start_consuming()


