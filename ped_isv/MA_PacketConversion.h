#ifndef MOTIONAPP_CONVERS_H
#define MOTIONAPP_CONVERS_H

#include <glm/glm.hpp>

class MA_PacketConversion
{
	MA_PacketConversion();
	
    unsigned char GetAccel(int *data, const unsigned char* packet) {
        m_Acceleration.x = ((packet[28] << 24) + (packet[29] << 16) + (packet[30] << 8) + packet[31]);
        m_Acceleration.y = ((packet[32] << 24) + (packet[33] << 16) + (packet[34] << 8) + packet[35]);
        m_Acceleration.z = ((packet[36] << 24) + (packet[37] << 16) + (packet[38] << 8) + packet[39]);
		return 0;
	}
    unsigned char GetAccel(short *data, const unsigned char* packet) {
        m_Acceleration.x = (packet[28] << 8) + packet[29];
        m_Acceleration.y = (packet[32] << 8) + packet[33];
        m_Acceleration.z = (packet[36] << 8) + packet[37];
		return 0;
	}

    unsigned char GetQuaternion(int *data, const unsigned char* packet) {
        m_Quaternion = glm::quat(((packet[0] << 24) + (packet[1] << 16) + (packet[2] << 8) + packet[3]),
                                 ((packet[4] << 24) + (packet[5] << 16) + (packet[6] << 8) + packet[7]),
                                 ((packet[8] << 24) + (packet[9] << 16) + (packet[10] << 8) + packet[11]),
                                 ((packet[12] << 24) + (packet[13] << 16) + (packet[14] << 8) + packet[15])) ;
		return 0;
	}
    unsigned char GetQuaternion(short *data, const unsigned char* packet) {
        m_Quaternion = glm::quat(((packet[0] << 8) + packet[1]),
                                 ((packet[4] << 8) + packet[5]),
                                 ((packet[8] << 8) + packet[9]),
                                 ((packet[12] << 8) + packet[13]));

		return 0;
	}

    unsigned char GetGyro(int *data, const unsigned char* packet) {
        m_Gyroscope.x = ((packet[16] << 24) + (packet[17] << 16) + (packet[18] << 8) + packet[19]);
        m_Gyroscope.y = ((packet[20] << 24) + (packet[21] << 16) + (packet[22] << 8) + packet[23]);
        m_Gyroscope.z = ((packet[24] << 24) + (packet[25] << 16) + (packet[26] << 8) + packet[27]);
		return 0;
	}
    unsigned char GetGyro(short *data, const unsigned char* packet) {
        m_Gyroscope.x = (packet[16] << 8) + packet[17];
        m_Gyroscope.y = (packet[20] << 8) + packet[21];
        m_Gyroscope.z = (packet[24] << 8) + packet[25];
		return 0;
	}

private:
    glm::vec3 m_Acceleration;
    glm::quat m_Quaternion;
    glm::vec3 m_Gyroscope;


};


/*
 * Particle::Update(float dt)
{
    Accel = vec3(0, 0, -9.81);
    vec3 OldVel = Vel;
    Vel = Vel + Accel * dt;
    Pos = Pos + (OldVel + Vel) * 0.5 * dt;
}
*/

#endif
