#ifndef GCOMPONENTCAMERA_H
#define GCOMPONENTCAMERA_H

#include "gincu/gcomponent.h"
#include "gincu/ggeometry.h"
#include "gincu/gcamera.h"

#include "cpgf/gflags.h"

namespace gincu {

class GTransform;
class GComponentTransform;
enum class GEntityEventType;

class GComponentCamera : public GComponent
{
private:
	typedef GComponent super;

public:
	inline static constexpr unsigned int getComponentType() {
		return componentTypeId_Camera;
	}

public:
	GComponentCamera();

	GComponentCamera * setViewport(const GRect & viewport) { this->camera.setViewport(viewport); return this; }
	const GRect & getViewport() const { return this->camera.getViewport(); }
	
	GComponentCamera * setSize(const GSize & size);
	const GSize & getSize() const { return this->camera.getSize(); }

	GComponentCamera * setMask(const uint32_t mask);
	uint32_t getMask() const { return this->camera.getMask(); }

	bool belongs(const unsigned int cameraId) const { return this->camera.belongs(cameraId); }
	const GCamera & getCamera() const { return this->camera; }

private:
	void onEntityEvent(GComponent * component, const GEntityEventType eventType);
	void doInitializeComponentTransform(GComponentTransform * componentTransform);

private:
	virtual void doAfterSetEntity() override;

private:
	GCamera camera;
};


} //namespace gincu


#endif
