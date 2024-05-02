#ifndef FPS_COUNTER_HPP
#define FPS_COUNTER_HPP
#include "Text.hpp"

class FPSCounter : public Text {
    private:
        static int max_count;
        int counter;
        float dt_average;
    public:
        FPSCounter();
        void Update(float dt) override;
};

#endif