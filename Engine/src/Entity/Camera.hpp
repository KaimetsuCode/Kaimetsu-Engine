#pragma once
#include <iostream>
#include <vector>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL2/SDL.h>

enum Camera_movement {
	FORWARD, BACKWARD, LEFT, RIGHT
};

struct DefaultCamera {
	static float yaw;
	static float pitch;
	static float speed;
	static float sensitivity;
	static float zoom;
};




class Camera {
public:
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
		glm::vec3 up = glm::vec3(0.0f, 1.0f,0.0f), 
		float yaw = DefaultCamera::yaw, 
		float pitch = DefaultCamera::pitch): front(glm::vec3(0.0f,0.0f,-1.0f)), movementSpeed(DefaultCamera::speed), mouseSensitivty(DefaultCamera::sensitivity), zoom(DefaultCamera::zoom) {
		this->position = position;
		this->worldUp = up;
		this->yaw = yaw;
		this->pitch = pitch;
		this->updateCameraVectors();
	}
	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) :
		front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(DefaultCamera::speed), mouseSensitivty(DefaultCamera::sensitivity), zoom(DefaultCamera::zoom) {
		this->position = glm::vec3(posX, posY, posZ);
		this->worldUp = glm::vec3(upX, upY, upZ);
		this->yaw = yaw;
		this->pitch = pitch;
		this->updateCameraVectors();
	}

	glm::mat4 GetViewMatrix() {
		return glm::lookAt(this->position, this->position + this->front, this->up);
	}

	void ProcessKeyboard(float deltaTime) {
		float velocity = this->movementSpeed * deltaTime;

        const Uint8* key = SDL_GetKeyboardState(NULL);
        if (key[SDL_SCANCODE_W]) {
            this->position += this->front * velocity;
        }
        if (key[SDL_SCANCODE_S]) {
            this->position -= this->front * velocity;
        }
        if (key[SDL_SCANCODE_A]) {
            this->position -= this->right * velocity;
        }
        if (key[SDL_SCANCODE_D]) {
            this->position += this->right * velocity;
        }
	}

	float lastXOffset = 0; 
	float lastYoffset = 0;

	void ProcessMouseMovement(float xOffset, float yOffset, float constrainPitch = true) {
		xOffset *= this->mouseSensitivty;
		yOffset *= this->mouseSensitivty;

		this->yaw += xOffset;
		this->pitch += yOffset;
		if (constrainPitch) {
			if (this->pitch > 89.0f) this->pitch = 89.0f;
			if (this->pitch < -89.0f) this->pitch = -89.0f;
		}
		this->updateCameraVectors();
	}

	void ProcessMouseScroll(float yOffset) {
		std::cout << "mouse scroll: " << yOffset << std::endl;
		if (this->zoom >= 1.0f && this->zoom <= 45.0f) {
			this->zoom -= yOffset;
		}
		if (this->zoom <= 1.0f)  this->zoom = 1.0f;
		if (this->zoom >= 45.0f) this->zoom = 45.0f;
	}

	float GetZoom() {
		return this->zoom;
	}

	glm::vec3 GetPosition() { return position; }

private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 worldUp;

	float yaw;
	float pitch;
	float zoom;
	float movementSpeed;
	float mouseSensitivty;

	void updateCameraVectors() {
		glm::vec3 front;
		front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		front.y = sin(glm::radians(this->pitch));
		front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		this->front = glm::normalize(front);
		this->right = glm::normalize(glm::cross(this->front, this->worldUp));
		this->up = glm::normalize(glm::cross(this->right, this->front));
	}
};