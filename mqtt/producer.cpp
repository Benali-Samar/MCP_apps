#include <mqtt/client.h> // for mosquitto client
#include <iostream>
#include <chrono>  //time   
#include <thread> //sleep 


int main()
{
  //the broker addr and port
  std::string ip = "localhost:1883";
  std::string id = "publisher";

  mqtt::client client(ip, id, mqtt::create_options(MQTTVERSION_5));

  client.connect();
  mqtt::message_ptr timeLeftMessagePointer = mqtt::make_message("consumer/in","");

  for(int i =10; i>0; --i)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    timeLeftMessagePointer -> set_payload("Time left: " + std::to_string(i));

    client.publish(timeLeftMessagePointer);
  }
  timeLeftMessagePointer -> set_payload("quit");
  client.publish(timeLeftMessagePointer);
  
  return 0;
}
