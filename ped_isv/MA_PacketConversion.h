#ifndef MOTIONAPP_CONVERS_H
#define MOTIONAPP_CONVERS_H

class MA_PacketConversion : IDataConversion
{
	MA_PacketConversion();
	
	static unsigned char GetAccel(int *data, const unsigned char* packet) {
		data[0] = ((packet[28] << 24) + (packet[29] << 16) + (packet[30] << 8) + packet[31]);
		data[1] = ((packet[32] << 24) + (packet[33] << 16) + (packet[34] << 8) + packet[35]);
		data[2] = ((packet[36] << 24) + (packet[37] << 16) + (packet[38] << 8) + packet[39]);
		return 0;
	}
	static unsigned char GetAccel(short *data, const unsigned char* packet) {
		data[0] = (packet[28] << 8) + packet[29];
		data[1] = (packet[32] << 8) + packet[33];
		data[2] = (packet[36] << 8) + packet[37];
		return 0;
	}

	static unsigned char GetQuaternion(int *data, const unsigned char* packet) {
		data[0] = ((packet[0] << 24) + (packet[1] << 16) + (packet[2] << 8) + packet[3]);
		data[1] = ((packet[4] << 24) + (packet[5] << 16) + (packet[6] << 8) + packet[7]);
		data[2] = ((packet[8] << 24) + (packet[9] << 16) + (packet[10] << 8) + packet[11]);
		data[3] = ((packet[12] << 24) + (packet[13] << 16) + (packet[14] << 8) + packet[15]);
		return 0;
	}
	static unsigned char GetQuaternion(short *data, const unsigned char* packet) {
		data[0] = ((packet[0] << 8) + packet[1]);
		data[1] = ((packet[4] << 8) + packet[5]);
		data[2] = ((packet[8] << 8) + packet[9]);
		data[3] = ((packet[12] << 8) + packet[13]);
		return 0;
	}

	static unsigned char GetGyro(int *data, const unsigned char* packet) {
		data[0] = ((packet[16] << 24) + (packet[17] << 16) + (packet[18] << 8) + packet[19]);
		data[1] = ((packet[20] << 24) + (packet[21] << 16) + (packet[22] << 8) + packet[23]);
		data[2] = ((packet[24] << 24) + (packet[25] << 16) + (packet[26] << 8) + packet[27]);
		return 0;
	}
	static unsigned char GetGyro(short *data, const unsigned char* packet) {
		data[0] = (packet[16] << 8) + packet[17];
		data[1] = (packet[20] << 8) + packet[21];
		data[2] = (packet[24] << 8) + packet[25];
		return 0;
	}
};

#endif
