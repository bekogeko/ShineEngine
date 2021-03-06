#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position):viewMat(1.0f), projMat(1.0f)
{
	Camera::width = width;
	Camera::height = height;

	Position = position;

}

void Camera::PerspectiveMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	glm::mat4 projection = glm::mat4(1.0f);
	
	viewMat = glm::lookAt(Position,Position+Orientation,Up);
	projMat = glm::perspective(FOVdeg, (float)(width / height), nearPlane, farPlane);
}

glm::mat4 Camera::GetViewMatrix()
{
	viewMat = glm::lookAt(Position, Position + Orientation, Up);
	return viewMat;
}

glm::mat4 Camera::GetProjMatrix()
{
	return projMat;
}



/*
#include "../stdafx.h"
#include "Camera.h"

glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f);

Camera::Camera() :
	m_view(1.0f), m_position(0, 0, 0), m_Quat()
{


}

glm::vec3* Camera::GetPositionPointer() {
	return &m_position;
}


void Camera::Refresh()
{
	glm::mat4 translate = glm::translate(-m_position);
	m_view = glm::mat4(m_Quat) * translate;
}



void Camera::SetRotation(glm::vec3& eulerAngles)
{
	m_rotation = eulerAngles;
	m_Quat = glm::quat(glm::radians(m_rotation));
}

void Camera::Rotate(glm::vec3 rot)
{
	m_rotation += rot;
	m_Quat = glm::quat(glm::radians(m_rotation));
}

void Camera::SetPosition(glm::vec3 pos)
{
	m_position = pos;
}

void Camera::Translate(glm::vec3 pos)
{
	m_position += pos;
}

glm::mat4 Camera::GetViewMatrix()
{
	return m_view;
}

glm::mat4 Camera::GetProjMatrix()
{
	return glm::perspective(
		((float)640 / 480) / (16.0f / 9.0f), // FOV
		640.0f / 480.0f, // aspect ratio
		0.1f, //near
		10.0f //far
	);
}
*/
