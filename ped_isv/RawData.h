#ifndef RAWDATA_H
#define RAWDATA_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

class RawData
{
public:
    RawData(unsigned short nbByte, const unsigned char* packet = NULL);
    void convertPacket(const unsigned char *packet, const float dt);
    void setPacket(const unsigned char *packet, const float dt);
    glm::vec3 getPosition(float dt);
private:
    bool ComputeAccel();
    bool ComputeQuaternion();
    bool ComputeGyro();

    glm::vec3 m_Position;
    glm::vec3 m_Acceleration;
    glm::quat m_Quaternion;
    glm::vec3 m_Gyroscope;
    glm::vec3 m_Velocity;

    const unsigned char* m_Packet;
    unsigned short m_NbByte;

};

#endif // RAWDATA_H
