#include <iostream>
#include <mqtt/client.h> // the mosquitto client


int main()
{
  //broker addres,port,id
  std::string ip = "localhost:1883";
  std::string id = "consumer";

  //creating a client using the ip and id 
  mqtt::client client(ip,id,mqtt::create_options(MQTTVERSION_5));

  //connect the client to establish connection
  client.connect();

  //the topic
  client.subscribe("in");

  //client's message proccessing loop 
  client.start_consuming();

  bool running = true;
  while(running)
  {
    //message pointer to hold the incomming message
    mqtt::const_message_ptr messagePointer;

    //if tge lsg is consumed so it will return true
    if(client.try_consume_message(&messagePointer))
    {
      //construct a string from the payload
      std::string messageString = messagePointer ->get_payload_str();
      
      //printf the payload msg 
      std::cout << messageString <<std::endl;

      // if it is quit than break
      if(messageString == "quit")
        running = false;
    }
  }
  return 0;
}
