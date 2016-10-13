#ifndef LEARN_CNN_CNNDERIVATIVEFUNCTION_H
#define LEARN_CNN_CNNDERIVATIVEFUNCTION_H
#include "math/ALIGradientDecent.h"
#include "LayerWrap.h"
namespace ALCNN {
    class CNNDerivativeFunction : public ALIGradientDecent::DerivativeFunction
    {
    public:
        virtual ALFloatMatrix* vCompute(ALFloatMatrix* coefficient, const ALFloatMatrix* Merge) const override;
        
        CNNDerivativeFunction(ALSp<LayerWrap> first, ALSp<LayerWrap> last, int outputSize);
        virtual ~ CNNDerivativeFunction();
    private:
        ALSp<LayerWrap> mFirst;
        ALSp<LayerWrap> mLast;
        int mOutputSize;
        ALFLOAT mDecay;
        mutable ALFLOAT mCurrentLoss;
    };
}
#endif