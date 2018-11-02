#include "camera.h"

Camera::Camera(glm::vec3 position/* = glm::vec3(0.0f, 0.0f, 0.0f)*/,
	glm::vec3 up/* = glm::vec3(0.0f, 1.0f, 0.0f)*/,
	float yaw/* = YAW*/, float pitch/* = PITCH*/):
m_Front(glm::vec3(0.0f, 0.0f, -1.0f)),
m_MovementSpeed(SPEED),
m_MouseSensitivity(SENSITIVEITY),
m_Zoom(ZOOM)
{
	m_Position = position;
	m_WorldUP = up;
	m_Yaw = yaw;
	m_Pitch = pitch;
	UpdatedCameraVectors();
}


Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch):
m_Front(glm::vec3(0.0f, 0.0f, -1.0f)),
m_MovementSpeed(SPEED),
m_MouseSensitivity(SENSITIVEITY),
m_Zoom(ZOOM)
{
	m_Position = glm::vec3(posX, posY, posZ);
	m_WorldUP = glm::vec3(upX, upY, upZ);
	m_Yaw = yaw;
	m_Pitch = pitch;
	UpdatedCameraVectors();
}

Camera::~Camera()
{

}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

void Camera::ProcessKeyboard(Camera_Movment direction, float deltaTime)
{
	float velocity = m_MovementSpeed * deltaTime;

	if (direction == FORWARD)
	{
		m_Position += m_Front * velocity;
	}
	else if (direction == BACKWARD)
	{
		m_Position -= m_Front * velocity;
	}
	else if (direction == LEFT)
	{
		m_Position -= m_Right * velocity;
	}
	else if (direction == RIGHT)
	{
		m_Position += m_Right * velocity;
	}
}


void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch/* = true*/)
{
	xoffset *= m_MouseSensitivity;
	yoffset *= m_MouseSensitivity;

	m_Yaw += xoffset;
	m_Pitch += yoffset;

	// Make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (m_Pitch > 89.0f)
		{
			m_Pitch = 89.0f;
		}

		if (m_Pitch < -89.0f)
		{
			m_Pitch = -89.0f;
		}
	}

	// Update Front, Right and Up Vectors using the updated Euler angles
	UpdatedCameraVectors();
}

// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void Camera::ProcessMouseScroll(float yoffset)
{
	if (m_Zoom >= 1.0f && m_Zoom <= 45.0f)
	{
		m_Zoom -= yoffset;
	}
	if (m_Zoom <= 1.0f)
		m_Zoom = 1.0f;
	if (m_Zoom >= 45.0f)
		m_Zoom = 45.0f;
}

// Calculates the front vector from the Camera's (updated) Euler Angles
void Camera::UpdatedCameraVectors()
{
	// Calculate the new Front vector
	glm::vec3 front;
	front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	front.y = sin(glm::radians(m_Pitch));
	front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

	m_Front = glm::normalize(front);
	// Also re-calculate the Right and Up vector
	m_Right = glm::normalize(glm::cross(m_Front, m_WorldUP));
	m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}
