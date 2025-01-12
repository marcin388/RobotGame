#ifndef QUATCAMERA_H
#define QUATCAMERA_H

class QuatCamera 
{

private:

	float _fieldOfView;
	float _nearPlane;
	float _farPlane;
	float _aspectRatio;

	//The camera coordinate axes
	glm::vec3 _xaxis;
	glm::vec3 _yaxis;
	glm::vec3 _zaxis;

	//Camera position vector and Quaternoin to represent camera orientation
	glm::vec3 _position;
	glm::vec3 _camPosition;
	glm::quat _orientation;

	glm::quat xRotation;
	glm::quat yRotation;
	glm::quat zRotation;

	glm::mat4 _view;
	glm::mat4 _projection;


public:

	QuatCamera();  //Constructor

	const glm::vec3& position() const; //position getter method
	const glm::quat& orientation() const; //position getter method

	void setPosition(const glm::vec3& position); //position setter method

	float fieldOfView() const; //fieldOfView getter method
	void setFieldOfView(float fieldOfView); //fieldOfView setter method

	float aspectRatio() const; //aspectRatio getter method
	void setAspectRatio(float aspectRatio);  //aspectRatio setter method

	float nearPlane() const;  //nearPlane getter method
	float farPlane() const;   //farPlane getter method
	void setNearAndFarPlanes(float nearPlane, float farPlane); //nearPlane and farPLane setter method


	void rotate(const float yaw, const float pitch); //Rotate camera
	void freeRotate(const float yaw, const float pitch); //Rotate camera
	void pan(const float x, const float y);  //Pan camera
	void roll(const float z); //Roll camera
	void zoom(const float z); //Zoom camera


	void updateView();  //Update the camera

	void reset(void); //Reset the camera

	void setCamPosition(glm::vec3 position);	//used for resetting camera position to robot

	void resetPosition(glm::quat orientation, glm::vec3 position);

	glm::mat4 view(); //Get the View matrix

	glm::mat4 projection(); //Get the Projection matrix

};	

#endif //QUATCAMERA_H


