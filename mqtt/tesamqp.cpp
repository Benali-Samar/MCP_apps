#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rabbitmq-c/amqp.h>
#include <rabbitmq-c/tcp_socket.h>

int main() {
    const char* hostname = "localhost";
    int port = 5672;
    const char* username = "mqtt-test";
    const char* password = "mqtt-test";
    const char* exchange = "myexchange";
    const char* routing_key = "mytopic";
    const char* virtual_host = "/";
    const char* message_body = "test shiittt";
    
     // Establish a connection
    amqp_connection_state_t conn = amqp_new_connection();
    amqp_socket_t* socket = amqp_tcp_socket_new(conn);
    amqp_socket_open(socket, hostname, port);
    
    // Login to RabbitMQ server
    amqp_login(conn, virtual_host,  0, 131072, 0, AMQP_SASL_METHOD_PLAIN, username, password);
    
    // Create a channel
    amqp_channel_open(conn, 1);
    amqp_get_rpc_reply(conn);
    
    // Declare the exchange
    amqp_exchange_declare(conn, 1, amqp_cstring_bytes(exchange), amqp_cstring_bytes("fanout"), 0, 0, 0, 0, amqp_empty_table);
    amqp_get_rpc_reply(conn);
    
    // Publish a message
    amqp_basic_properties_t props;
    props._flags = AMQP_BASIC_CONTENT_TYPE_FLAG | AMQP_BASIC_DELIVERY_MODE_FLAG;
    props.content_type = amqp_cstring_bytes("text/plain");
    props.delivery_mode = 2; // Persistent

    amqp_basic_publish(conn, 1, amqp_cstring_bytes(exchange), amqp_cstring_bytes(routing_key), 0, 0, &props, amqp_cstring_bytes(message_body));
    amqp_get_rpc_reply(conn);
    
    // Clean up and close the connection
    amqp_channel_close(conn, 1, AMQP_REPLY_SUCCESS);
    amqp_connection_close(conn, AMQP_REPLY_SUCCESS);
    amqp_destroy_connection(conn);
    
    return 0;
}

