//
//  LSTMLayer.hpp
//  abs
//
//  Created by jiangxiaotang on 02/11/2016.
//  Copyright © 2016 jiangxiaotang. All rights reserved.
//

#ifndef LSTMLayer_hpp
#define LSTMLayer_hpp

#include <stdio.h>
#include "ILayer.h"
namespace ALCNN {
    class LSTMLayer : public ILayer
    {
    public:
        virtual void vForward(const ALFloatMatrix* before, ALFloatMatrix* after, const ALFloatMatrix* parameters, ALFloatMatrix* cache) const override;
        virtual void vBackward(const ALFloatMatrix* after_diff, const ALFloatMatrix* after, const ALFloatMatrix* parameters, const ALFloatMatrix* before, ALFloatMatrix* before_diff, ALFloatMatrix* parameters_diff, ALFloatMatrix* cache) const override;
        
        LSTMLayer(size_t iw, size_t ow, size_t t);
        virtual ~ LSTMLayer(){}
        
    private:
        size_t mTime;
        size_t mInputSize;
        size_t mOutputSize;
    };
};
#endif /* LSTMLayer_hpp */
