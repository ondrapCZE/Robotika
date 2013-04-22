#define WIN32_LEAN_AND_MEAN
#define _USE_MATH_DEFINES
#include "tim310.h"
#include "findBall.h"
#include <iostream>
#include <cmath>

#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include "Protocol.h"

int main(){

	Tim310_CLASS tim;
	if(!tim.open()){
		std::cerr << "Nepovedlo se otevrit Tim310" << std::endl ;
		exit(1);
	}

	/*FindBall_CLASS ballFinder(M_PI/180.0);

	while(true){
		uint16_t* data = NULL;
		int count;

		ballFinder.findBall(tim.readData());
	}*/
	
	
	local = SICK_POSITION_DATA_SYNCHRONIZATION;

	while(true){
		using namespace boost::asio::ip;
		using namespace std;

		std::vector<uint16_t> data = tim.readData();
		SICKAndPositionData_packet* packet = SICKAndPositionData_packet::createInstance(0,0,0,0,0,0,4.0,3.0*M_PI_2, data);
		
		try{
			cout << "Attemp to connect ondrap." << endl;
			boost::asio::io_service io_service;

			tcp::socket mySocket(io_service);
				
			boost::asio::ip::tcp::endpoint robotEndpoint(boost::asio::ip::address::from_string("127.0.0.1"), 2000);
			mySocket.connect(robotEndpoint);
			cout << "Socket connected." << endl;

			void* packetPtr = packet;
			size_t packetSize = sizeof(PacketHeader) + packet->header.payloadLength;

			boost::system::error_code error;
			mySocket.write_some(boost::asio::buffer(packetPtr, packetSize), error);

			if (error){ cerr << error.message() << endl; }
			
			cout << "Packet was send: " << packet->toString() << endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
		SICKAndPositionData_packet::deleteInstance(packet);
	}
}