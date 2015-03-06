#include "RawData.h"

RawData::RawData(unsigned short nbByte, const unsigned char *packet) :
    m_NbByte(nbByte),
    m_Packet(new unsigned char[40]),
    m_Velocity(0)
{
    m_Packet = packet;
}

void
RawData::convertPacket(const unsigned char *packet, const float dt)
{
    m_Packet = packet;
    if(m_Packet != NULL){
        ComputeAccel();
        ComputeGyro();
        ComputeQuaternion();
    }
    getPosition(dt);

}

bool
RawData::ComputeAccel()
{
    if(m_NbByte > 16){
        m_Acceleration.x = ((m_Packet[28] << 24) + (m_Packet[29] << 16) + (m_Packet[30] << 8) + m_Packet[31]);
        m_Acceleration.y = ((m_Packet[32] << 24) + (m_Packet[33] << 16) + (m_Packet[34] << 8) + m_Packet[35]);
        m_Acceleration.z = ((m_Packet[36] << 24) + (m_Packet[37] << 16) + (m_Packet[38] << 8) + m_Packet[39]);
    } else {
        m_Acceleration.x = (m_Packet[28] << 8) + m_Packet[29];
        m_Acceleration.y = (m_Packet[32] << 8) + m_Packet[33];
        m_Acceleration.z = (m_Packet[36] << 8) + m_Packet[37];
    }
    return 1;
}

bool
RawData::ComputeGyro()
{
    if(m_NbByte > 16){
        m_Gyroscope.x = ((m_Packet[16] << 24) + (m_Packet[17] << 16) + (m_Packet[18] << 8) + m_Packet[19]);
        m_Gyroscope.y = ((m_Packet[20] << 24) + (m_Packet[21] << 16) + (m_Packet[22] << 8) + m_Packet[23]);
        m_Gyroscope.z = ((m_Packet[24] << 24) + (m_Packet[25] << 16) + (m_Packet[26] << 8) + m_Packet[27]);
    } else {
        m_Gyroscope.x = (m_Packet[16] << 8) + m_Packet[17];
        m_Gyroscope.y = (m_Packet[20] << 8) + m_Packet[21];
        m_Gyroscope.z = (m_Packet[24] << 8) + m_Packet[25];
    }
    return 1;
}

bool
RawData::ComputeQuaternion()
{
    if(m_NbByte > 16){
        m_Quaternion = glm::quat(((m_Packet[0] << 24) + (m_Packet[1] << 16) + (m_Packet[2] << 8) + m_Packet[3]),
                                 ((m_Packet[4] << 24) + (m_Packet[5] << 16) + (m_Packet[6] << 8) + m_Packet[7]),
                                 ((m_Packet[8] << 24) + (m_Packet[9] << 16) + (m_Packet[10] << 8) + m_Packet[11]),
                                 ((m_Packet[12] << 24) + (m_Packet[13] << 16) + (m_Packet[14] << 8) + m_Packet[15])) ;
    } else {
        m_Quaternion = glm::quat(((m_Packet[0] << 8) + m_Packet[1]),
                                 ((m_Packet[4] << 8) + m_Packet[5]),
                                 ((m_Packet[8] << 8) + m_Packet[9]),
                                 ((m_Packet[12] << 8) + m_Packet[13]));
    }
    return 1;
}

void
RawData::setPacket(const unsigned char *packet, const float dt)
{
    m_Packet = packet;
    if(m_Packet != NULL){
        ComputeAccel();
        ComputeGyro();
        ComputeQuaternion();
    }
    getPosition(dt);
}

glm::vec3
RawData::getPosition(float dt)
{
    glm::vec3 oldVel = m_Velocity;
    m_Velocity.x = m_Velocity.x + m_Acceleration.x * dt;
    m_Velocity.z = m_Velocity.z + m_Acceleration.z * dt;
    m_Position = m_Position + (oldVel + m_Velocity) * 0.5 * dt;
}
