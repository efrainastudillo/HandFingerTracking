#include "libraries.h"

class FrameUtilities{
public:
	FrameUtilities();
	~FrameUtilities();
	void calcHistogram(float* pHistogram, int histogramSize, const openni::VideoFrameRef& frame);
private:
};