#include "StochasticGradientDecent.h"
void StochasticGradientDecent::vOptimize(ALFloatMatrix* coefficient, const ALFloatMatrix* X, const DerivativeFunction* delta, double alpha, int iteration) const
{
    ALASSERT(alpha>0);
    ALASSERT(NULL!=coefficient);
    ALASSERT(NULL!=X);
    ALASSERT(NULL!=delta);
    ALASSERT(iteration >= 1);
    if (mBatchSize >= X->height())
    {
        mDegeneration.vOptimize(coefficient, X, delta, alpha, iteration);
        return;
    }
    for (int i=0; i<iteration; ++i)
    {
        ALSp<ALFloatMatrix> selectX = ALFloatMatrix::randomeSelectMatrix(X, mBatchSize);
        ALSp<ALFloatMatrix> deltaC = delta->vCompute(coefficient, selectX.get());
        ALFloatMatrix::linear(coefficient, coefficient, 1.0, deltaC.get(), -alpha);
        ALFloatMatrix::checkAndSet(coefficient, 0.0f);
    }
}
